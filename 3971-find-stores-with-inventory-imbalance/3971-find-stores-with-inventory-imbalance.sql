# Write your MySQL query statement below
WITH StoreStats AS (
    SELECT 
        s.store_id, 
        s.store_name, 
        s.location,
        MAX(i.price) AS max_price,
        MIN(i.price) AS min_price
    FROM stores s
    JOIN inventory i ON s.store_id = i.store_id
    GROUP BY s.store_id, s.store_name, s.location
    HAVING COUNT(DISTINCT i.product_name) >= 3
),
ProductsMaxMin AS (
    SELECT 
        i.store_id, 
        i.product_name, 
        i.quantity, 
        i.price
    FROM inventory i
    JOIN StoreStats ss ON i.store_id = ss.store_id
    WHERE i.price = ss.max_price OR i.price = ss.min_price
)
SELECT 
    ss.store_id,
    ss.store_name,
    ss.location,
    p_max.product_name AS most_exp_product,
    p_min.product_name AS cheapest_product,
    ROUND(p_min.quantity * 1.0 / p_max.quantity, 2) AS imbalance_ratio
FROM StoreStats ss
JOIN ProductsMaxMin p_max ON ss.store_id = p_max.store_id AND p_max.price = ss.max_price
JOIN ProductsMaxMin p_min ON ss.store_id = p_min.store_id AND p_min.price = ss.min_price
WHERE p_max.quantity < p_min.quantity
ORDER BY imbalance_ratio DESC, ss.store_name ASC;