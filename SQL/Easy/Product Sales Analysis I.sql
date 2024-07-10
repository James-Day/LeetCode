SELECT product_name, year, price
FROM Sales
    JOIN Product on Sales.product_id = Product.product_id