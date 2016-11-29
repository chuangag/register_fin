Register
  ===============

  This is a project for COMP2012H, 2016 Fall, HKUST

  The main purpose is to create a student registration system

  The course web page:
      http://course.cse.ust.hk/comp2012h
      (CSD account required)

  Author
  ===============
  Name: HUANG, Chia-hung
  Student ID: 20309206
  ITSC: chuangag

  How-to-compile-and-run
  ===============
  >make
  >./Register

  Technical Details
  ===============

  The build of this project involves the following tools:
      Xcode
      Git (manage code)

  Source file tree:
      Register
      |
      |--include
      |  |--objects.h
      |  |--doublySortedLinkedList.h
      |  |--hashTable.h
      |  |--courseRecord.h
      |
      |--src
      |  |--main.cpp
      |  |--objects.cpp
      |
      |--Makefile

  Design of the project:
      I basicly follow the project requirement.
      There are several points I would like to mention:
      1. BUGs and how I fixed them
        a. Segementation fault when deleting:
          Sol: Beware the usage of stl::list::erase
        b. Double printing when operation finished:
          Sol: Check the sequence of printing and overloading notprint version of functions
        c. Returning local variable when not found
          Sol: initialize a static object for returning, avoid returning local varialbe by reference, which is DANGEROUS
        d. Double deletion of CourseRecord
          Sol: Double the checkpoints before every deletion to avoid double deletion
        e. Template fuction doesn't apply to pointer type
          Sol: Use Template Specialization and re-wirte all and added function for pointer type

      2. Points to improve
        a. CourseRecord includes hashTable.h which cause problem of double define fuctions when seperating implementation, maybe can re-write in another way
        b. write valid input checking into functions, although at first I don't think I need to reuse them. However I did, and even not reusing them, it will make the code more readable.

      3. Good idea
        a. Using string type for every input, this simplify input checking since I can apply string operation no matter what is the input information, such as
        checking if is all number or if is upper letters.
        b. Placing valid input checking in set functions and use set functions whenever need to input new informations, this simplify the code
        c. Seperate the 5 menus using functions, and swith between them is intuitive
        d.overloading == and < for each data type, so that stl::sort can be apply directly without specifying compare function
        e. function overloading such as print and notprint version

--- end of README ---