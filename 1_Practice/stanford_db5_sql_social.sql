/* Stanford Online Course: DB5 SQL */
/* SQL Social-Network Query Exercises */

/* Delete the tables if they already exist */
drop table if exists Highschooler;
drop table if exists Friend;
drop table if exists Likes;

/* Create the schema for our tables */
create table Highschooler(ID int, name text, grade int);
create table Friend(ID1 int, ID2 int);
create table Likes(ID1 int, ID2 int);

/* Populate the tables with our data */
insert into Highschooler values (1510, 'Jordan', 9);
insert into Highschooler values (1689, 'Gabriel', 9);
insert into Highschooler values (1381, 'Tiffany', 9);
insert into Highschooler values (1709, 'Cassandra', 9);
insert into Highschooler values (1101, 'Haley', 10);
insert into Highschooler values (1782, 'Andrew', 10);
insert into Highschooler values (1468, 'Kris', 10);
insert into Highschooler values (1641, 'Brittany', 10);
insert into Highschooler values (1247, 'Alexis', 11);
insert into Highschooler values (1316, 'Austin', 11);
insert into Highschooler values (1911, 'Gabriel', 11);
insert into Highschooler values (1501, 'Jessica', 11);
insert into Highschooler values (1304, 'Jordan', 12);
insert into Highschooler values (1025, 'John', 12);
insert into Highschooler values (1934, 'Kyle', 12);
insert into Highschooler values (1661, 'Logan', 12);

insert into Friend values (1510, 1381);
insert into Friend values (1510, 1689);
insert into Friend values (1689, 1709);
insert into Friend values (1381, 1247);
insert into Friend values (1709, 1247);
insert into Friend values (1689, 1782);
insert into Friend values (1782, 1468);
insert into Friend values (1782, 1316);
insert into Friend values (1782, 1304);
insert into Friend values (1468, 1101);
insert into Friend values (1468, 1641);
insert into Friend values (1101, 1641);
insert into Friend values (1247, 1911);
insert into Friend values (1247, 1501);
insert into Friend values (1911, 1501);
insert into Friend values (1501, 1934);
insert into Friend values (1316, 1934);
insert into Friend values (1934, 1304);
insert into Friend values (1304, 1661);
insert into Friend values (1661, 1025);
insert into Friend select ID2, ID1 from Friend;

insert into Likes values(1689, 1709);
insert into Likes values(1709, 1689);
insert into Likes values(1782, 1709);
insert into Likes values(1911, 1247);
insert into Likes values(1247, 1468);
insert into Likes values(1641, 1468);
insert into Likes values(1316, 1304);
insert into Likes values(1501, 1934);
insert into Likes values(1934, 1501);
insert into Likes values(1025, 1101);

/* Q1  (1 point possible)
Find the names of all students who are friends with someone named Gabriel. */

Select name
From Highschooler
Inner Join Friend
On Highschooler.ID = Friend.ID1
Where 
	name <> 'Gabriel'
	and
	(Friend.ID2 in
	(Select ID From Highschooler Where name = 'Gabriel')
	or
	Friend.ID1 in
	(Select ID From Highschooler Where name = 'Gabriel'));
	
/* Q2  (1 point possible)
For every student who likes someone 2 or more grades younger than themselves, return that student's name and grade, and the name and grade of the student they like. */

Select n1, gr1, name as n2,  grade as gr2
From
	(Select Likes.ID1, name as n1, grade as gr1, Likes.ID2
	From
		(Highschooler Inner Join Likes
		On Highschooler.ID = Likes.ID1)) as T1
	Inner Join Highschooler
	On Highschooler.ID = T1.ID2
Where
	gr1 - grade >= 2;

/* Q3  (1 point possible)
For every pair of students who both like each other, return the name and grade of both students. Include each pair only once, with the two names in alphabetical order. */

Select *
From
	(Select n1, gr1, name as n2,  grade as gr2
	From
		(Select LK.ID1, name as n1, grade as gr1, LK.ID2
		From
			(Highschooler Inner Join 
				(Select L1.ID1, L1.ID2
				From Likes L1, Likes L2
				where L1.ID1 < L2.ID1 
					and L1.ID1 = L2.ID2 
					and L1.ID2 = L2.ID1
				) as LK
			On Highschooler.ID = LK.ID1)) as T1
		Inner Join Highschooler
		On Highschooler.ID = T1.ID2
	Where
		n1 <= name
	Union
	Select name as n2,  grade as gr2, n1, gr1
	From
		(Select LK.ID1, name as n1, grade as gr1, LK.ID2
		From
			(Highschooler Inner Join 
				(Select L1.ID1, L1.ID2
				From Likes L1, Likes L2
				where L1.ID1 < L2.ID1 
					and L1.ID1 = L2.ID2 
					and L1.ID2 = L2.ID1
				) as LK
			On Highschooler.ID = LK.ID1)) as T1
		Inner Join Highschooler
		On Highschooler.ID = T1.ID2
	Where
		name <= n1) as Tmp
Order by n1, n2

/* Q4  (1/1 point)
Find all students who do not appear in the Likes table (as a student who likes or is liked) and return their names and grades. Sort by grade, then by name within each grade. */

Select name, grade
From Highschooler
Where not
	(ID in 
		(Select ID1 From Highschooler
         Inner Join Likes On Highschooler.ID = Likes.ID1)
	or
	ID in
		(Select ID2 From Highschooler
         Inner Join Likes On Highschooler.ID = Likes.ID2))
		 
/* Q5  (1/1 point)
For every situation where student A likes student B, but we have no information about whom B likes (that is, B does not appear as an ID1 in the Likes table), return A and B's names and grades. */

Select n1, gr1, name as n2,  grade as gr2
From
	(Select Likes.ID1, name as n1, grade as gr1, Likes.ID2
	From
		(Highschooler Inner Join Likes
		On Highschooler.ID = Likes.ID1)) as T1
	Inner Join Highschooler
	On Highschooler.ID = T1.ID2
Where
	ID2 not in (Select ID1 From Likes)
	
/* Q6  (1 point possible)
Find names and grades of students who only have friends in the same grade. Return the result sorted by grade, then by name within each grade. */

Select name, grade
From
	(Select ID1
	From
		(Select ID1, gr1, max(gr2) as mx, min(gr2) as mi
		From
			(Select ID1, gr1, ID2, grade as gr2
			From
				(Select ID1, grade as gr1, ID2
				 From Highschooler Join Friend On Highschooler.ID = Friend.ID1) as T1
			Inner Join Highschooler On Highschooler.ID = T1.ID2) as T2
		Group by ID1) as T3
	Where gr1 = mx and gr1 = mi) as T4
Inner Join Highschooler On T4.ID1 = Highschooler.ID
Order by grade, name;

/* Q7  (1 point possible)
For each student A who likes a student B where the two are not friends, find if they have a friend C in common (who can introduce them!). For all such trios, return the name and grade of A, B, and C. */

Select T5.n1, T5.gr1, T5.n2, T5.gr2, name as n3, grade as gr3 From
(Select T4.ID1, T4.n1, T4.gr1, T4.ID2, name as n2, grade as gr2, T4.fID1 From
(Select T3.ID1, name as n1, grade as gr1, T3.ID2, T3.fID1 From
	(Select T2.ID1, T2.ID2, fID1
	From
		(Select T1.ID1, Friend.ID2 as fID1, T1.ID2
		From
			(Select *
			From Likes
			Where Likes.ID2 not in 
				(Select Friend.ID2 From Friend Where Friend.ID1 = Likes.ID1)) as T1
		Inner Join Friend On Friend.ID1 = T1.ID1) as T2
	Inner Join Friend On Friend.ID1 = T2.ID2
	Where fID1 = Friend.ID2) as T3
Inner Join Highschooler On Highschooler.ID = T3.ID1) as T4
Inner Join Highschooler On Highschooler.ID = T4.ID2) as T5
Inner Join Highschooler On Highschooler.ID = T5.fID1

/* Q8  (1 point possible)
Find the difference between the number of students in the school and the number of different first names. */

Select cp-cn
From
	(Select count(*) as cp From Highschooler) as T0,
	(Select count(*) as cn
	From (Select count(*) From Highschooler Group by name) as T1) as T2
	
/* Q9  (1 point possible)
Find the name and grade of all students who are liked by more than one other student. */

Select name, grade
From
	(Select T1.ID2 From
		(Select Likes.ID2, count(*) as ln From Likes Group by ID2) as T1
	Where ln >= 2) as T2
Inner Join Highschooler On Highschooler.ID = T2.ID2

