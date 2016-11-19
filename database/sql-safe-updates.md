# SQL safe updates
update or delete record without specifying a key(ex. primary key) in the where clause.

* error : You are using safe update mode and you tried to update a table without a WHERE that uses a KEY column To disable safe mode, toggle the option ....

```sql
SET SQL_SAFE_UPDATES = 0;
UPDATE tablename SET columnname = 1;
SET SQL_SAFE_UPDATES = 1;
```