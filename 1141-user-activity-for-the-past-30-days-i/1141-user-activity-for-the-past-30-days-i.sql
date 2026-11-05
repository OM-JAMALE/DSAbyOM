# Write your MySQL query statement below
select activity_date as day , count(DISTINCT(user_id)) as active_users
from Activity 
where ((activity_date > "2019-06-27" AND activity_date < "2019-07-28"))
group by activity_date 
order by activity_date ASC
;