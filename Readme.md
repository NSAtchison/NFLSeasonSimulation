# Final Project Details
CS171 Whitworth University, Dr. Qian Mao, Scott Griffith  
Reference to Jones and other CS faculty  
Last Modified 11/14/2021  

# Important Dates:
**(Optional) Proposal due: before Friday 12/3/2021**  
**Presentations on:**  
**Section 1: Tuesday 12/14/2021 10:30AM**  
**Section 2: Wednesday 12/15/2021 1PM**  
**Section 3: Thursday 12/16/2021 1PM**  
**Final write up due: Saturday 12/18/2021 by 8AM**

# Evaluation
As always, you will be graded on:
- Follow style guide
- Good and proper comments (headers and useful documentation)
- Appropriate variable re-use
- Good functionalization and formation

### Grade Breakdown
| Final Project                | Grade |
|------------------------------|-------|
| Code Deliverable             |  50   |
| Documentation                |  25   |
| Presentation                 |  25   |
|  __Total__                   |  100  |

As a reminder this project forms 25% of your final grade. *The work you turn in should reflect this.*

# Motivation
The goal of the final project is to show off what you have learned through the semester. Rather than give a final exam, we would rather see your ability expressed through accomplishing a goal using code. This document outlines the basics for the project and how it will be delivered, but you are welcome and encouraged to go above and beyond. Work beyond what is expected will be recognized and __extra points will be awarded__.

## General Requirements
For this project, the following requirements must be met:  
  * Use appropriate code development and functionalization
  * Use appropriate types and structures when solving your problem
  * Optional, but suggested: Use object-oriented programming where applicable

You are going to be defining some problem you are going to be solving with your code. I intentionally want to leave that up to you. 

This project may be completed as a group of two or individually. If you are working in a group, the expectation is that the overall effort will reflect such. All code will be written utilizing **pair programming**, utilizing whatever appropriate tools (`WhitGit`,Live Share extension). This means that both group members will be actively engaged when code is being worked on. The rest of the work should be evenly divided among the group and all group members should review all work before submitting it.

All artifacts, with the exception of the individual feedback sent via email, will be submitted via a group-specific Whitgit repository that will be set up once groups have been assigned. For non-code things you are welcome and encouraged to submit links instead of uploading. This includes presentation material, code documentation and design material. Just make sure access settings are correctly set. If we cannot get to it, we cannot grade it! 

## Project Proposal (optional)
After some brainstorming, you can submit a project proposal for review. This is not required, but **highly suggested**. We will review your plan and give you a thumbs up, or a suggestion of how to make the project either more rigorous (the solution would be too easy) or how to re-frame the problem to make is easier to solve (your planned solution is too difficult for this level class).

You don't want to be the person that finds out after that their work is not sufficient for the class. That stinks for me and it will stink for you.

These proposals need to be submitted __before__ Friday 12/3/2021.
 
## Deliverables

While some things have a more specific due date (see the presentation information below) the collection of all your work is due by Saturday 12/18/2021 at 8AM. Anything turned in after that time will not be graded. 

### Documentation
You will submit a document (.md, .docx, .pdf) in your final project repository that contains the following:
* Detailed description of what the project is attempting to do, the problem this project attempts to solve and/or a detailed purpose statement.
* An accounting of any assumptions made both when designing the project or when running the program. This could be things like a data format you are using or assumptions about the user's actions. If you don't put anything here an your code breaks when we use it, you did something wrong.
* Flowchart of how the different functions and algorithms are connected. Each function should be annotated with the first line of the function header (the part that describes what the function does). Each connection of data should be clear about if it is an input or an output and what form the data takes.
* Detailed analysis, overview and justification of your design. Why did you develop your code the way you did? Does it do what you want it to do?  
* Manual for how to run your project in the form of a `README.md` file the repository folder.
* Works Cited. This includes any libraries used, any sources and any code utilized that was not specifically written for this project. These citations should be mirrored in your code. Remember to keep in mind approved sources for the course.
  
This document should be 2-3 pages minimum leaving out the flowchart diagrams. A single sentence for each of the above bullets is not what we are looking for.

Your code must be appropriately commented. This includes headers for every method/function and file headers.

As a note, detailed means: "having many details or facts; showing attention to detail". This means that we should have _zero_ questions about what you did, how you did it and why. Look at how long this document is. This is just the documentation for the framework of the project. Take that into consideration when developing your documentation.

__If working in a group__: each group member will email their instructor (qmao@whitworth.edu or sgriffith@whitworth.edu) on the Friday of finals week an individual and confidential reflection of how the project went with a review of their group member. This will be worth 5% of your overall project grade. You should answer the following in this email:
* How did the project go? What went well? What would you do differently?
* How was the project split? How did the pair programming work?
* Would you work with your group partner again? Were there any issues?

### Presentation

During your section's final exam slot, you will participate in the presentation of these final projects. You are expected to show respect to your classmates and engage with their cool projects, as they are expected to engage with your presentation. 

Your presentation should:
* outline your project and what you made
* highlight the algorithmic points of your program
* include a demonstration of project running
  * This could be captured (screen shots, video) or live demo
* identify future work on the project
* reflection on the lessons learned developing code

Your presentation should not:
* be a code review. Selections of code are fine, but we don't need to see every line of code. We want to see results!

Each section has 2 hours for final presentations. We will be calculating time based on: `numTeams / 2 hours = presentationTime`. This means if there are 14 teams, each team will get ~8.5 minutes (minus transition time). You have a lot to cover: concise and clear presentations are necessary.  

Make sure all group members participate in the presentation.

### Project Implementation
As with all code turned in for this class, the same rules apply here for this final project.  

You will be graded on proper coding style. Your code must be readable and have good comments describing what is going on. Variable names should make sense, classes and their methods should be obvious, and variables should be descriptive. Use proper indentation.  

One of the main themes of this semester has been abstraction, functionalization and proper code re-use. Each function should only do one thing. If it is doing many things, those should be functionalized.

Your code should line up with your documentation. All citations should be clearly marked and identified.

#### Example of 'Proper' Code
Included with this document is an example of a project that did something correct, but many things incorrectly. If you are curious what a well formed project looks like vs. a poorly formed project.

`example1_main.cpp` - This is a NCAA bracket simulator. The basic premise of the program is to simulate a full NCAA basketball tournament. 

`example2_main.cpp` - Is functionally the same program (both output very similar outputs), but is written in a *much* more intentional form.

Notes:
* Line count is not always the best metric, but notice that `example1` is 4502 lines long (with just the main being almost 1200 lines). `example2` in totality is only 447 lines. The both do the same thing. Remember: code re-use!
* Sometimes when doing complicated things you need lots of lines of code, that is ok! (`example2` lines 375-438)
* Sometimes when doing simple things you can make one function that can be used over and over again.
  * Just about every function in `example1` is replaced with a single `play_game` function in `example2`
* If you notice you are repeating a bunch (copy/pasting) there is probably a better way to do it (`example1`'s whole main)