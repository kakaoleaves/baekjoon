-- 코드를 입력하세요
SELECT CATEGORY, SUM(SALES) AS TOTAL_SALES
FROM BOOK_SALES NATURAL JOIN BOOK
WHERE SALES_DATE >= '2022-01-01' AND SALES_DATE < '2022-02-01'
GROUP BY CATEGORY
ORDER BY CATEGORY ASC;