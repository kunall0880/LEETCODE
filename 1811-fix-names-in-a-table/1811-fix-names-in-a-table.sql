select user_id,concat(Upper(substr(name,1,1)),lower(substr(name,2,length(name)))) as "name"
from users
order by (user_id);