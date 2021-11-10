select cart_id from cart_products
where name in ("Milk", "Yogurt")
group by cart_id
having count(distinct(name)) > 1
order by cart_id
