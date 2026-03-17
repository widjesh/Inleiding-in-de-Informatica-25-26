# 🐦 Bird Clinic

## Overview
Welcome to our bird clinic! This is a project made by 4 students of the Anton de Kom University of Suriname (ADEKUS) <br>
Those students (with their student numbers and github accounts) are: <br>
* **Ishaan Oedit 20250004** <br> @ishoediah
* **Amaris Gobind 20240732** <br> @amarisgx
* **Amalesh Sewratan 20250154** <br> @amalesh2007
* **Ishita Goerdin 20250133** <br> @kayliegoerdin

We are students majoring in Electrical Engineering. This is our first C++ project for the course Inleiding Informatica (Introduction to Computer Science). This project is to demonstrate our understanding of the basics of C++. The minimun requirements were using an if else logic, loops, classes, objects and arrays. Instead of an array we used a vector to better handle memory management and because it would fit better into our project.

## 🏥 Bird clinic and our project
A bird clinic is a veterinary facility specializing in the medical care, diagnosis, treatment and grooming of birds.

### How our project helps
Normal bird clinics use stamps to identify and store birds. These stamps are physical pieces of paper on which information of the bird is manually written. These stamps can be hard to work with, as they need to be stored correctly to prevent the loss or destruction of it. Writing information or looking through all stamps can also take a lot of time. That is why we have digitalized this process. Now storing information of birds, creating new digital "stamps" and viewing that information has become easier and robust.

## 💻 How does the program work
This program is made to follow *CRUD* operations. The code for this program consist of 3 parts. The classes, the functions and the workflow. We also have an external database which is a text file called `bird_objects_list_saved.txt`. The first part, classes, is where the Bird class is made with all the attributes that are needed for a clinic. <br>

After that we have functions, which are the `createNewBird`, `saveBird`, `birdLookupAll`, `birdlookupSpecific`, `removeBirdByID` , `editBirdAttribute` and the `exit` function. 

The create new bird function works by using user input for the attributes and then creating a new object using those attributes. The save function works by using `ofstream` to open our database file and saving te birds into that file. 

The `birdLookupAll` function works by loading all the birds, which are saved in the database file, into a vector and using `getline` to make the "," the delimiter for the attributes. 

The `Lookupspecific`, `removeBird` and `editBird` all work by first using the `birdLookupAll` function to load all birds into a vector. From there, the birdlookup specific asks for an ID through user input and loops through the vector and looks for a bird with the matching ID. The `removeBird` function also loops trough the vector, but removes the bird with the matching ID. The `editBird` function loops trough the vector to look for a matching ID and allows you to choose and edit an attribute and then updates that attribute. The `editBird` and `removeBird` function then update the vector with the changes you want and thus "updates" the database. <br>

The workflow consists in the int main and uses if-else functions and do-while loops. When running the code, you can either choose to view the birds database (which is more a public option) or going to an administrator menu (which as the name suggests is for administrators only and requires a password). The menu works by user input and navigating through the menu using if else functions and do while loops. This allows for a good user experience.

The naming convention we used in this project is camelCase.

(PS: for anyone wanting to try our program, the administrator password is Masala)

## 💁‍♂️ What have we learned from this project
We have learned many thing from this project<br>
* We have learned the basics of how C++ works and how to work with fuctions, objects, memory management and more
* We have learned how to use this knowledge and these skills to solve a real world problem. This gave us experience and knowleadge on how to approach and solve real world problems, especially using C++ and programming to provide solutions
* We have learned how to use version control , git, and github to upload and receive code that we and other people have worked on
* We have learned how to work together in a solution offering coding environment. This gave us insights on how problems can be approached as a group on how we can code and solve problems together.

## 🚀 The future of our project and what could be improved
There are plans to further improve on this project. This includes building a web interface for this project so it can be used commercially. There will also be an actual database implementation like a DBMS. This will make this project a commercial product which can be used worldwide.

---

As a final note, we would like to thank our lecturer Shiva Bhaggan ( @widjesh) for teaching us this class and helping us through this process of making this program. Thank you!
