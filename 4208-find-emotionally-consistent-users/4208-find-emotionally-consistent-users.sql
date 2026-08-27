# Write your MySQL query statement below
WITH ReactionCounts AS (
    SELECT 
        user_id, 
        reaction, 
        COUNT(*) AS cnt
    FROM reactions
    GROUP BY user_id, reaction
),
UserStats AS (
    SELECT 
        user_id, 
        MAX(cnt) AS max_cnt, 
        SUM(cnt) AS total_cnt
    FROM ReactionCounts
    GROUP BY user_id
)
SELECT 
    s.user_id, 
    c.reaction AS dominant_reaction, 
    ROUND(s.max_cnt * 1.0 / s.total_cnt, 2) AS reaction_ratio
FROM UserStats s
JOIN ReactionCounts c ON s.user_id = c.user_id AND s.max_cnt = c.cnt
WHERE s.total_cnt >= 5 
  AND ROUND(s.max_cnt * 1.0 / s.total_cnt, 2) >= 0.60
ORDER BY reaction_ratio DESC, s.user_id ASC;