--查询张三老师讲授的任意一门课的学生姓名

select TId from teacher where Tname='张三';

select Student.* from Student where Student.Sid not in
(
select SC.Sid from SC where 
SC.CId in(select CId from Course where Course.TId in 
(select TId from teacher where Tname='张三')));

select *
from student 
where student.SId not in 
(
select student.SId
from student left join sc on student.SId=sc.SId 
where EXISTS 
(select *
from teacher ,course
where teacher.Tname='张三'
and   teacher.TId=course.TId
and 	course.CId=sc.CId))



--两门及以上不及格学生的信息

select SC.Sid,Count(SC.score) 课程总数 from SC group by SC.Sid having count(SC.score)>=2;

select Student.* from Student where Student.Sid in
(select Sid from
(select * from SC where sc.score<60) low60
group by low60.Sid
having count(low60.score)>=2);

select Student.Sid,Student.Sname,avg(sc.score)
from Student,SC
where Student.Sid=SC.Sid
and sc.score<60
GROUP by Student.SId
HAVING count(*)>=2

select student.SId,student.Sname,avg(sc.score)
from student ,sc
where student.SId=sc.SId
and   sc.score<60
GROUP BY sc.SId
HAVING count(*)>=2

--查询01课程小于60分的学生信息，降序
Select Student.*
from Student,SC
where sc.cid='01'
AND Student.Sid=SC.Sid
AND sc.score<60
order by sc.score desc;

select student.*
from student,sc
where sc.CId ='01'
and   sc.score<60
and   student.SId=sc.SId


select F.sid,F.cid,S.G,score from 
(select Student.Sid,SC.cid,SC.score
from Student,SC
where Student.Sid=SC.Sid) F,
(select sid,avg(score) G
from sc 
group by sid) S
where F.sid=S.sid
order by S.G;

--查询各科成绩最高分、最低分和平均分：

select Course.Cid,Course.Cname,max(score),min(score),avg(score)
from SC,Course
where SC.Cid=Course.Cid
group by SC.cid

select SC.cid,Count(*) 及格人数
from SC
where sc.score>60
group by SC.cid;

select * from SC order by Cid;

select sc.CId ,max(sc.score)as 最高分,min(sc.score)as 最低分,AVG(sc.score)as 平均分,
count(*)as 选修人数,sum(case when sc.score>=60 then 1 else 0 end )/count(*)as 及格率,
sum(case when sc.score>=70 and sc.score<80 then 1 else 0 end )/count(*)as 中等率,
sum(case when sc.score>=80 and sc.score<90 and sc.score<80 then 1 else 0 end )/count(*)as 优良率,
sum(case when sc.score>=90 then 1 else 0 end )/count(*)as 优秀率 
from sc
GROUP BY sc.CId
ORDER BY count(*)DESC,sc.CId asc

select sc.SId,sc.CId ,case when @pre_parent_code=sc.CId then @curRank:=@curRank+1 when @pre_parent_code:=sc.CId then  @curRank:=1  end as rank,sc.score
from (select @curRank:=0,@pre_parent_code:='') as t ,sc
ORDER by sc.CId,sc.score desc

select *
from SC
group by SC.cid;

select *
from sc  
where  (select count(*) from sc as a where sc.CId =a.CId and  sc.score <a.score )<3
ORDER BY CId asc,sc.score desc

select A.Cid ,A.score,A.Sid,B.Cid,B.score,B.Sid from SC A,SC B WHERE A.Cid=B.Cid order by A.cid;
select * from SC order by SC.Cid;

select a.sid,b.sid from sc as a,sc as b --where b.CId =a.CId and  b.score <a.score