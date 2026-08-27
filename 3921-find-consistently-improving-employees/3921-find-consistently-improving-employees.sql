# Write your MySQL query statement below
WITH ReviewDeltas AS (
    SELECT 
        employee_id,
        ROW_NUMBER() OVER (PARTITION BY employee_id ORDER BY review_date DESC) AS rn,
        LAG(rating) OVER (PARTITION BY employee_id ORDER BY review_date DESC) - rating AS delta
    FROM performance_reviews
)
SELECT 
    r.employee_id,
    e.name,
    SUM(r.delta) AS improvement_score
FROM ReviewDeltas r
JOIN employees e ON r.employee_id = e.employee_id
WHERE r.rn IN (2, 3)
GROUP BY r.employee_id, e.name
HAVING COUNT(r.delta) = 2 AND MIN(r.delta) > 0
ORDER BY improvement_score DESC, e.name ASC;