-- 코드를 입력하세요
SELECT M.CART_ID
FROM CART_PRODUCTS AS M, CART_PRODUCTS AS Y
WHERE M.CART_ID=Y.CART_ID
AND M.NAME='Milk'
AND Y.NAME='Yogurt'
ORDER BY CART_ID;