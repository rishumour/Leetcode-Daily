WITH SeasonSales AS (
    SELECT 
        CASE 
            WHEN MONTH(s.sale_date) IN (12, 1, 2) THEN 'Winter'
            WHEN MONTH(s.sale_date) IN (3, 4, 5) THEN 'Spring'
            WHEN MONTH(s.sale_date) IN (6, 7, 8) THEN 'Summer'
            ELSE 'Fall' 
        END AS season,
        p.category,
        SUM(s.quantity) AS total_quantity,
        SUM(s.quantity * s.price) AS total_revenue
    FROM Sales s
    JOIN Products p ON s.product_id = p.product_id
    GROUP BY season, p.category
),
Ranked AS (
    SELECT 
        season, 
        category,
        total_quantity,
        total_revenue,
        ROW_NUMBER() OVER(
            PARTITION BY season 
            ORDER BY total_quantity DESC, total_revenue DESC, category ASC
        ) AS rnk
    FROM SeasonSales
)
SELECT 
    season, 
    category, 
    total_quantity, 
    total_revenue
FROM Ranked
WHERE rnk = 1
ORDER BY season ASC;