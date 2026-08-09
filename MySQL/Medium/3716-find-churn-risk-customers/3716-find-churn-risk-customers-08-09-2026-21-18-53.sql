# Write your MySQL query statement below
WITH user_stats AS (
    SELECT
        user_id,
        FIRST_VALUE(event_type) OVER (
            PARTITION BY user_id
            ORDER BY event_date DESC, event_id DESC
        ) AS last_event_type,

        FIRST_VALUE(plan_name) OVER (
            PARTITION BY user_id
            ORDER BY event_date DESC, event_id DESC
        ) AS current_plan,

        FIRST_VALUE(monthly_amount) OVER (
            PARTITION BY user_id
            ORDER BY event_date DESC, event_id DESC
        ) AS current_monthly_amount,

        MAX(monthly_amount) OVER (
            PARTITION BY user_id
        ) AS max_historical_amount,

        MIN(event_date) OVER (
            PARTITION BY user_id
        ) AS first_event_date,

        MAX(event_date) OVER (
            PARTITION BY user_id
        ) AS last_event_date,

        MAX(
            CASE
                WHEN event_type = 'downgrade' THEN 1
                ELSE 0
            END
        ) OVER (
            PARTITION BY user_id
        ) AS has_downgrade
    FROM subscription_events
),

users AS (
    SELECT DISTINCT
        user_id,
        last_event_type,
        current_plan,
        current_monthly_amount,
        max_historical_amount,
        first_event_date,
        last_event_date,
        has_downgrade
    FROM user_stats
)

SELECT
    user_id,
    current_plan,
    current_monthly_amount,
    max_historical_amount,
    DATEDIFF(last_event_date, first_event_date) AS days_as_subscriber
FROM users
WHERE last_event_type <> 'cancel'
  AND has_downgrade = 1
  AND current_monthly_amount < 0.5 * max_historical_amount
  AND DATEDIFF(last_event_date, first_event_date) >= 60
ORDER BY
    days_as_subscriber DESC,
    user_id ASC;