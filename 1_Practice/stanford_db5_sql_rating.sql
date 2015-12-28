/* Stanford Online Course: DB5 SQL */
/* SQL Movie-Rating Query Exercises */

/* Delete the tables if they already exist */
drop table if exists Movie;
drop table if exists Reviewer;
drop table if exists Rating;

/* Create the schema for our tables */
create table Movie(mID int, title text, year int, director text);
create table Reviewer(rID int, name text);
create table Rating(rID int, mID int, stars int, ratingDate date);

/* Populate the tables with our data */
insert into Movie values(101, 'Gone with the Wind', 1939, 'Victor Fleming');
insert into Movie values(102, 'Star Wars', 1977, 'George Lucas');
insert into Movie values(103, 'The Sound of Music', 1965, 'Robert Wise');
insert into Movie values(104, 'E.T.', 1982, 'Steven Spielberg');
insert into Movie values(105, 'Titanic', 1997, 'James Cameron');
insert into Movie values(106, 'Snow White', 1937, null);
insert into Movie values(107, 'Avatar', 2009, 'James Cameron');
insert into Movie values(108, 'Raiders of the Lost Ark', 1981, 'Steven Spielberg');

insert into Reviewer values(201, 'Sarah Martinez');
insert into Reviewer values(202, 'Daniel Lewis');
insert into Reviewer values(203, 'Brittany Harris');
insert into Reviewer values(204, 'Mike Anderson');
insert into Reviewer values(205, 'Chris Jackson');
insert into Reviewer values(206, 'Elizabeth Thomas');
insert into Reviewer values(207, 'James Cameron');
insert into Reviewer values(208, 'Ashley White');

insert into Rating values(201, 101, 2, '2011-01-22');
insert into Rating values(201, 101, 4, '2011-01-27');
insert into Rating values(202, 106, 4, null);
insert into Rating values(203, 103, 2, '2011-01-20');
insert into Rating values(203, 108, 4, '2011-01-12');
insert into Rating values(203, 108, 2, '2011-01-30');
insert into Rating values(204, 101, 3, '2011-01-09');
insert into Rating values(205, 103, 3, '2011-01-27');
insert into Rating values(205, 104, 2, '2011-01-22');
insert into Rating values(205, 108, 4, null);
insert into Rating values(206, 107, 3, '2011-01-15');
insert into Rating values(206, 106, 5, '2011-01-19');
insert into Rating values(207, 107, 5, '2011-01-20');
insert into Rating values(208, 104, 3, '2011-01-02');

/* https://lagunita.stanford.edu/courses/DB/SQL/SelfPaced/courseware/ch-sql/seq-exercise-sql_movie_query_core/ */

/* Q1  (1/1 point)
Find the titles of all movies directed by Steven Spielberg. */

Select title
From Movie
Where director="Steven Spielberg";

/* Q2  (1/1 point)
Find all years that have a movie that received a rating of 4 or 5, and sort them in increasing order. */

Select distinct year
From Movie
Inner Join Rating
On Movie.mID = Rating.mID
Where Rating.stars >= 4
Order by year;

/* Q3  (1 point possible)
Find the titles of all movies that have no ratings. */

Select title
From Movie
Where mID not in 
	(Select mID From Rating);
	
/* Q4  (1 point possible)
Some reviewers didn't provide a date with their rating. Find the names of all reviewers who have ratings with a NULL value for the date. */

Select name
From Reviewer
Inner Join Rating
On Reviewer.rID = Rating.rID
Where Rating.ratingDate is null;

/* Q5  (1 point possible)
Write a query to return the ratings data in a more readable format: reviewer name, movie title, stars, and ratingDate. Also, sort the data, first by reviewer name, then by movie title, and lastly by number of stars.  */

Select name, title, stars, ratingDate
From Rating
Inner Join Movie On Rating.mID = Movie.mID
Inner Join Reviewer On Rating.rID = Reviewer.rID
Order by name, title, stars;

/* Q6  (1 point possible)
For all cases where the same reviewer rated the same movie twice and gave it a higher rating the second time, return the reviewer's name and the title of the movie. */

Select name, title
From
	(Select R1.mID, R1.rID
	From Rating as R1, Rating as R2
	Where 
		R1.rID = R2.rID
		and R1.mID = R2.mID
		and R1.stars > R2.stars 
		and R1.ratingDate > R2.ratingDate
	Order by R1.mID) as Tmp
Inner Join Movie On Tmp.mID = Movie.mID
Inner Join Reviewer On Tmp.rID = Reviewer.rID;

/* Q7  (1 point possible)
For each movie that has at least one rating, find the highest number of stars that movie received. Return the movie title and number of stars. Sort by movie title. */
Select title, max(stars)
From Rating
Inner Join Movie On Rating.mID = Movie.mID
Group by Movie.mID
Order by title;

/* Q8  (1 point possible)
For each movie, return the title and the 'rating spread', that is, the difference between highest and lowest ratings given to that movie. Sort by rating spread from highest to lowest, then by movie title. */

Select title, max(stars)-min(stars) as diff
From Rating
Inner Join Movie On Rating.mID = Movie.mID
Group by Movie.mID
Order by diff desc, title;

/* Q9  (1 point possible)
Find the difference between the average rating of movies released before 1980 and the average rating of movies released after 1980. (Make sure to calculate the average rating for each movie, then the average of those averages for movies before 1980 and movies after. Don't just calculate the overall average rating before and after 1980.) */

Select A1.av - A2.av
From
	(Select avg(st) as av
	From
		(Select title, year, avg(stars) as st
		From Rating
		Inner Join Movie On Rating.mID = Movie.mID
		Group by Movie.mID) as avgSt
	Where year < 1980) as A1
	Inner Join
	(Select avg(st) as av
	From	
		(Select title, year, avg(stars) as st
		From Rating
		Inner Join Movie On Rating.mID = Movie.mID
		Group by Movie.mID) as avgSt
	Where year >= 1980) as A2;
	
/* https://lagunita.stanford.edu/courses/DB/SQL/SelfPaced/courseware/ch-sql/seq-exercise-sql_movie_query_extra/ */

/* Q1  (1 point possible)
Find the names of all reviewers who rated Gone with the Wind. */

Select name
From Rating
Inner Join Movie On Rating.mID = Movie.mID
Inner Join Reviewer On Rating.rID = Reviewer.rID
Where title = "Gone with the Wind"
Group by Rating.rID;

/* Q2  (1 point possible)
For any rating where the reviewer is the same as the director of the movie, return the reviewer name, movie title, and number of stars. */

Select name, title, stars
From Rating
Inner Join Movie On Rating.mID = Movie.mID
Inner Join Reviewer On Rating.rID = Reviewer.rID
Where name = director;

/* Q3  (1 point possible)
Return all reviewer names and movie names together in a single list, alphabetized. (Sorting by the first name of the reviewer and first word in the title is fine; no need for special processing on last names or removing "The".) */

Select name From Reviewer
union
Select title From Movie
Order by name;

/* Q4  (1 point possible)
Find the titles of all movies not reviewed by Chris Jackson. */

Select title
From Movie
Where mID not in
	(Select Movie.mID
	From Rating
	Inner Join Movie On Rating.mID = Movie.mID
	Inner Join Reviewer On Rating.rID = Reviewer.rID
	Where name = 'Chris Jackson');

/* Q5  (1 point possible)
For all pairs of reviewers such that both reviewers gave a rating to the same movie, return the names of both reviewers. Eliminate duplicates, don't pair reviewers with themselves, and include each pair only once. For each pair, return the names in the pair in alphabetical order. */

Select distinct R1.name, R2.name
From 
	(Select Rating.rID, mID, name from Rating 
	Inner Join Reviewer On Reviewer.rID = Rating.rID)
	as R1,
	(Select Rating.rID, mID, name from Rating 
	Inner Join Reviewer On Reviewer.rID = Rating.rID)
	as R2
Where 
	R1.name < R2.name
	and R1.mID = R2.mID
Order by R1.name, R2.name;

/* Q6  (1 point possible)
For each rating that is the lowest (fewest stars) currently in the database, return the reviewer name, movie title, and number of stars. */

Select name, title, stars
From Rating
Inner Join Movie On Rating.mID = Movie.mID
Inner Join Reviewer On Rating.rID = Reviewer.rID
Where stars = (Select min(stars) From Rating);

/* Q7  (1 point possible)
List movie titles and average ratings, from highest-rated to lowest-rated. If two or more movies have the same average rating, list them in alphabetical order. */

Select title, avg(stars)
From Rating
Inner Join Movie On Rating.mID = Movie.mID
Inner Join Reviewer On Rating.rID = Reviewer.rID
Group by Rating.mID
Order by avg(stars) desc, title;

/* Q8  (1 point possible)
Find the names of all reviewers who have contributed three or more ratings. (As an extra challenge, try writing the query without HAVING or without COUNT.)  */

Select name
From Reviewer
Where rID in
	(Select distinct R1.rID
	From Rating R1, Rating R2, Rating R3
	Where
		R1.rID = R2.rID and R2.rID = R3.rID 
		and not
		(R1.mID = R2.mID and R1.stars = R2.stars and R1.ratingDate = R2.ratingDate
		or
    	R1.mID = R3.mID and R1.stars = R3.stars and R1.ratingDate = R3.ratingDate
    	or
    	R2.mID = R3.mID and R2.stars = R3.stars and R2.ratingDate = R3.ratingDate));
		
/* Q9  (1 point possible)
Some directors directed more than one movie. For all such directors, return the titles of all movies directed by them, along with the director name. Sort by director name, then movie title. (As an extra challenge, try writing the query both with and without COUNT.) */

Select title, Movie.director
From Movie
Inner Join
	(Select director, count(distinct mID) as ct
	From Movie
	Group by director) as Tmp
On Movie.director = Tmp.director
Where Tmp.ct = 2
Order by Movie.director, title;

/* Q10  (1 point possible)
Find the movie(s) with the highest average rating. Return the movie title(s) and average rating. (Hint: This query is more difficult to write in SQLite than other systems; you might think of it as finding the highest average rating and then choosing the movie(s) with that average rating.) */

Select title, cat
From Movie 
Inner Join
	(Select mID, cat
	From (Select mID, avg(stars) as cat From Rating Group by mID) as T0
	Where cat = 
		(Select max(at) From (Select mID, avg(stars) as at From Rating Group by mID) as T1)) as Tmp
On Movie.mID = Tmp.mID;


/* Q11  (1 point possible)
Find the movie(s) with the lowest average rating. Return the movie title(s) and average rating. (Hint: This query may be more difficult to write in SQLite than other systems; you might think of it as finding the lowest average rating and then choosing the movie(s) with that average rating.) */

Select title, cat
From Movie 
Inner Join
	(Select mID, cat
	From (Select mID, avg(stars) as cat From Rating Group by mID) as T0
	Where cat = 
		(Select min(at) From (Select mID, avg(stars) as at From Rating Group by mID) as T1)) as Tmp
On Movie.mID = Tmp.mID;

/* Q12  (1 point possible)
For each director, return the director's name together with the title(s) of the movie(s) they directed that received the highest rating among all of their movies, and the value of that rating. Ignore movies whose director is NULL. */

Select distinct T1.director, T1.title, T1.stars
From
	(Select director, title, stars
	From Rating
	Inner Join Movie On Rating.mID = Movie.mID) as T1
Inner Join
	(Select director, max(stars) as mstar
	From Rating
	Inner Join Movie On Rating.mID = Movie.mID
	Group by director) as T2
On T1.director = T2.director
Where T1.stars = T2.mstar;
