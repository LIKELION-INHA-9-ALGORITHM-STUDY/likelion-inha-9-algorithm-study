select t1.cart_id from cart_products t1
left join cart_products t2
on t1.cart_id = t2.cart_id
where t1.name = "Milk" and t2.name = "Yogurt"
group by t1.cart_id
order by t1.cart_id