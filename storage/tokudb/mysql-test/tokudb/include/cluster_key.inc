# test for TokuDB clustering keys.
# test assumes that a table 't1' exists with the following columns:
# a int, b int, c int, d int
insert into t1 values
  (1,10,100,1000),(2,20,200,2000),(3,30,300,3000),(4,40,400,4000),
  (5,50,500,5000),(6,60,600,6000),(7,70,700,7000),(8,80,800,8000),
  (9,90,900,9000),(10,100,1000,10000),(11,110,1100,11000);


#normal queries

# ignore rows column
--replace_column 9 NULL;
explain select * from t1 where a > 5;
select * from t1 where a > 5;

# ignore rows column
--replace_column 9 NULL;
explain select * from t1 where b > 70;
select * from t1 where b > 70;

# ignore rows column
--replace_column 9 NULL;
explain select * from t1 where c > 950;
select * from t1 where c > 950;

#covering indexes

# ignore rows column
--replace_column 9 NULL;
explain select a from t1 where a > 10;
select a from t1 where a > 10;

# ignore rows column
--replace_column 9 NULL;
explain select a,b from t1 where b > 30;
select a,b from t1 where b > 30;

# ignore rows column
--replace_column 9 NULL;
explain select a,b from t1 where c > 350;
select a,c from t1 where c > 350;


alter table t1 add index bdca(b,d,c,a) clustering=yes;
insert into t1 values (10,10,10,10);
alter table t1 drop index bdca;

alter table t1 drop primary key;
# ignore rows column
--replace_column 9 NULL;
explain select * from t1 where a > 5;
select * from t1 where a > 5;

# ignore rows column
--replace_column 9 NULL;
explain select * from t1 where b > 70;
select * from t1 where b > 70;

# ignore rows column
--replace_column 9 NULL;
explain select * from t1 where c > 950;
select * from t1 where c > 950;

#covering indexes

# ignore rows column
--replace_column 9 NULL;
explain select b from t1 where b > 70;
select b from t1 where b > 70;

# ignore rows column
--replace_column 9 NULL;
explain select b from t1 where c > 950;
select c from t1 where c > 950;

alter table t1 add e varchar(20);

alter table t1 add primary key (a,b,c);

# ignore rows column
--replace_column 9 NULL;
explain select * from t1 where a > 8;
select * from t1 where a > 8;

# ignore rows column
--replace_column 9 NULL;
explain select * from t1 where b > 70;
select * from t1 where b > 70;

# ignore rows column
--replace_column 9 NULL;
explain select * from t1 where c > 950;
select * from t1 where c > 950;

#covering indexes

# ignore rows column
--replace_column 9 NULL;
explain select a from t1 where a > 10;
select a from t1 where a > 10;

# ignore rows column
--replace_column 9 NULL;
explain select a,b from t1 where b > 30;
select a,b from t1 where b > 30;

# ignore rows column
--replace_column 9 NULL;
explain select a,b from t1 where c > 350;
select a,c from t1 where c > 350;


alter table t1 drop primary key;
# ignore rows column
--replace_column 9 NULL;
explain select * from t1 where a > 5;
select * from t1 where a > 5;

# ignore rows column
--replace_column 9 NULL;
explain select * from t1 where b > 70;
select * from t1 where b > 70;

# ignore rows column
--replace_column 9 NULL;
explain select * from t1 where c > 950;
select * from t1 where c > 950;

#covering indexes
# ignore rows column
--replace_column 9 NULL;
explain select b from t1 where b > 70;
select b from t1 where b > 70;

# ignore rows column
--replace_column 9 NULL;
explain select b from t1 where c > 950;
select c from t1 where c > 950;


