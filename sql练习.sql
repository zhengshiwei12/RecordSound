create table Student(SId varchar(10),Sname varchar(10),Sage datetime,Ssex varchar(10));
insert into Student values('01' , '赵雷' , '1990-01-01' , '男');
insert into Student values('02' , '钱电' , '1990-12-21' , '男');
insert into Student values('03' , '孙风' , '1990-05-20' , '男');
insert into Student values('04' , '李云' , '1990-08-06' , '男');
insert into Student values('05' , '周梅' , '1991-12-01' , '女');
insert into Student values('06' , '吴兰' , '1992-03-01' , '女');
insert into Student values('07' , '郑竹' , '1989-07-01' , '女');
insert into Student values('09' , '张三' , '2017-12-20' , '女');
insert into Student values('10' , '李四' , '2017-12-25' , '女');
insert into Student values('11' , '李四' , '2017-12-30' , '女');
insert into Student values('12' , '赵六' , '2017-01-01' , '女');
insert into Student values('13' , '孙七' , '2018-01-01' , '女');

select * from Student;
create table Course(CId varchar(10),Cname nvarchar(10),TId varchar(10));
insert into Course values('01' , '语文' , '02');
insert into Course values('02' , '数学' , '01');
insert into Course values('03' , '英语' , '03');
select * from Course;
create table Teacher(TId varchar(10),Tname varchar(10));
insert into Teacher values('01' , '张三');
insert into Teacher values('02' , '李四');
insert into Teacher values('03' , '王五');
select * from Teacher;


create table SC(SId varchar(10),CId varchar(10),score decimal(18,1));
insert into SC values('01' , '01' , 80);
insert into SC values('01' , '02' , 90);
insert into SC values('01' , '03' , 99);
insert into SC values('02' , '01' , 70);
insert into SC values('02' , '02' , 60);
insert into SC values('02' , '03' , 80);
insert into SC values('03' , '01' , 80);
insert into SC values('03' , '02' , 80);
insert into SC values('03' , '03' , 80);
insert into SC values('04' , '01' , 50);
insert into SC values('04' , '02' , 30);
insert into SC values('04' , '03' , 20);
insert into SC values('05' , '01' , 76);
insert into SC values('05' , '02' , 87);
insert into SC values('06' , '01' , 31);
insert into SC values('06' , '03' , 34);
insert into SC values('07' , '02' , 89);
insert into SC values('07' , '03' , 98);
select * from SC;
show tables;

--查询01课程的成绩
select count(*) AS 数量
    from (select Student.Sname,Course.Cname,SC.score,Teacher.Tname 
    from Student,Course,SC,Teacher 
    where Student.Sid=Sc.Sid and Course.Cid=Sc.Cid And Teacher.Tid=Course.Tid) T;

select Student.Sname AS 姓名,t1.score AS 分数 from Student,
(select Sid,score from SC sc where sc.Cid='01') as t1, 
(select Sid,score from SC sc where sc.Cid='02') as t2
where t1.Sid=t2.Sid and t1.score>t2.score and Student.Sid=t1.Sid;

--同时有01和02课程

--有1课程的学生
select * from
(select Student.SId,Student.Sname,SC.score AS Score1
from Student,SC
where Student.SId=SC.SId and SC.CId='01') AS has01 
left join 
(select Student.SId,Student.Sname,SC.score AS Score2
from Student,SC
where Student.SId=SC.SId and SC.CId='02') AS has02
on has01.SId=has02.SId;

select Student.Sname from Student where Student.SId in (select t1.SId
from (select SId ,score from sc where sc.CId='01')as t1 , (select SId ,score from sc where sc.CId='02') as t2
where t1.SId=t2.SId);

select Student.Sname,m.score from Student,(select t1.Sid,t1.score
from (select SId ,score from sc where sc.CId='01')as t1 , (select SId ,score from sc where sc.CId='02') as t2
where t1.SId=t2.SId) AS m where m.SId=Student.SId;
select *
from (select SId ,score from sc where sc.CId='01')as t1 left join  (select SId ,score from sc where sc.CId='02') as t2
on t1.SId=t2.SId;


select Student.Sname,Course.Cname
from Student,SC,Course
where Student.Sid=SC.Sid and Course.Cid=SC.Cid;

select Student.Sname from Student
where Student.Sid not in (select SId from SC where sc.Cid="01");--查询所有有01课程的学生id

select Student.Sname from Student where Student.Sid in
(select sc.Sid from sc
where sc.Sid not in (select SId from sc where sc.Cid='01') and sc.Cid='02');


select Student.Sname,AVG(score) AS 分数
    from Student,Course,SC 
    where Student.Sid=Sc.Sid and Course.Cid=Sc.Cid
    group by SC.Sid
    having avg(score)>60;

select Course.Cname,AVG(score) AS 分数
    from Student,Course,SC 
    where Student.Sid=Sc.Sid and Course.Cid=Sc.Cid
    group by Course.Cid;


select Sname from Student where Student.Sid in (select Sid from SC);

select distinct Student.* from Student,SC where Student.Sid=SC.Sid;


select Student.Sid,Student.Sname,Count(*) AS 课程总数,sum(SC.socre) AS 总成绩
from Studnet,SC
where Student.Sid=SC.sid
group by Student.Sid;

select Student.Sname,AVG(score) 平均分,sum(score) 总分,count(score) 课程总数
from Student,SC
where Student.Sid=SC.sid
group by Student.Sid;

select student.SId,student.Sname,t1.sumscore,t1.coursecount
from student ,(
select SC.SId,sum(sc.score)as sumscore ,count(sc.CId) as coursecount
from sc 
GROUP BY sc.SId) as t1
where student.SId =t1.SId

select teacher.Tname,count(*) from teacher where Teacher.Tname like '李%';


--学过张三老师的可得学生

--老师颤三教的课程id
select Tid from Teacher where Teacher.Tname='张三';
select Cid,Cname from Course where Course.Tid in (select Tid from Teacher where Teacher.Tname='张三');
select *
from Student
where Student.Sid in
(select Sid from SC where SC.Cid in (select Cid from Course where Course.Tid in 
(select Tid from Teacher where Teacher.Tname='张三')));

select student.*
from teacher  ,course  ,student,sc
where teacher.Tname='张三'
and   teacher.TId=course.TId
and   course.CId=sc.CId
and   sc.SId=student.SId

-- 查询没有学完所有课程的学生信息
--所以课程的数量

select count(*) 课程数量 from Course;
-- 每个学生课程数量
select Student.Sid,Student.Sname,Count(SC.score) AS 课程数量
from Student left join SC
on Student.Sid=SC.Sid
group by Student.Sid
having Count(SC.score)=(select count(*) 课程数量 from Course);

select Student.*,count(Student.Sid)
from Student left JOIN SC on Student.Sid=SC.Sid 
group by(Student.SId) having count(Student.Sid)<3;

select Student.*
from Student
where Student.Sid not in
(select Sid from SC 
group by Sid
having count(Cid)=(select count(*) 课程数量 from Course));

select student.*
from student 
where student.SId not in ( select sc.SId
from sc
group by sc.SId
having count(*)=(select count(CId) from course))

-- 查询与01号同学学习完全相同的其他同学的信息



select Student.* from Student 
where Student.Sid not in

and Student.Sid!='01';

select * from Student left join SC on Student.Sid=SC.Sid;

select t1.SId A,sc.SId B
from 
(select student.SId,t.CId
from student ,(select sc.CId from sc where sc.SId='05') as t )as t1 
left join sc on t1.SId=sc.SId and t1.CId=sc.CId


select * from Course union all select * from Course;

select student.SId,t.CId
from student ,(select sc.CId from sc where sc.SId='01') as t 

select * 
from
(select *
from 
(select *
from student ,(select sc.CId from sc where sc.SId='05') as t )as t1 
left join sc on t1.SId=sc.SId and t1.CId=sc.CId
union
select * from 
(select *
from student ,(select sc.CId from sc where sc.SId='05') as t) as t2
right join sc on t2.SId=sc.SId and t2.CId=sc.CId) as m
where m.CId is null AND m.Sname is null


SELECT * FROM student WHERE sid NOT IN(
SELECT t1.sid FROM (SELECT t1.sid,t2.score FROM (SELECT t1.sid,t2.cid FROM student t1,(SELECT cid FROM sc WHERE sid = '01') t2) t1 LEFT JOIN sc t2 ON t1.sid = t2.sid AND t1.cid = t2.cid) t1 WHERE t1.score IS NULL
) AND sid NOT IN(
SELECT t1.t2_sid 'sid' FROM (SELECT t1.sid 't1_sid',t2.sid 't2_sid',t2.score FROM (SELECT t1.sid,t2.cid FROM `student` t1,(SELECT cid FROM `sc` WHERE sid = '01') t2) t1 RIGHT JOIN sc t2 ON t1.sid = t2.sid AND t1.cid = t2.cid) t1 WHERE t1.t1_sid IS NULL
)