In the following page it is going to be explained what is a Static Code Analysis tool and how to use them in your own Visual Studio projects.

I am <link to your linkedIn>(NAME LASTNAME), student of the <https://www.citm.upc.edu/ing/estudis/graus-videojocs/>(Bachelor’s Degree in Video Games by UPC at CITM). This content is generated for the second year’s subject Project 2, under supervision of lecturer <https://es.linkedin.com/in/ricardpillosu>(Ricard Pillosu).

## What does it mean Static Code Analysis?

Static: not done in runtime, unlike dynamic code analysis.
Code: referent to a program, a set of them, or an entire system.
Analysis: check for problems and possible improvements.

So, SCA is a tool which looks for errors on a specific set of code, before the execution.

## What are it's uses?

Calculate performance metrics.
Ensure code security against hack attempts.
Enforce coding standards.
Analyze structures and dependencies.
Provide accurate and meaningful error descriptions.
Identify anomalies or flaws in the code.

## How does it work?

Let's check how does work Coverity, an online SCA tool. The functionality described in the video can be extrapolated to most current SCA tools in the market.

https://community.synopsys.com/s/article/Coverity-Tutorial-Introduction-to-Coverity

## SCA tools (offline)

Most commonly used compilers featu
However, dedicated SCA programs can provide better performance, support more programming languages or display better error definitions.
Some offline SCA tools are:
CodeSonar ( Paid / Static and binary analysis / analysis of third-party code included)
CheckMark products ( Paid / lots of features / dedicated products / supports +20 languages)
CppCheck ( Free / we will check it later )

## SCA tools (online)

Some online SCA tools allow to copy the code fragment to analyze directly into their webpage.
However, the main benefit of online tools comes when used in sync with a code storage service (Git, Bitbucket).
This allows to automatic and continuous evaluation of the code written by all team members.
Some online SCA tools are:
Coverity ( Paid/ integrated with Git/ supports Java, C++, C# Python and Ruby)
QonCAT (Paid/ supports multiple languages / quality analysis and metrics)

# Tutorial

Next, it's provided a brief tutorial so readers can easily implement SCA tools into their projects.
Each step of the tutorial will be named as TODO X.

### TODO 0

First, we must download the necessary files. The installation files for CppCheck and Visual Code Grepper can be found in their respective websites:
http://cppcheck.sourceforge.net/
https://sourceforge.net/projects/visualcodegrepp/

Alternatively, they are included in the latest release of the Github repository linked to this web, which also contains a small test program to chech SCA functionality. You can use any project he wishes to analyze, yet it must be kept in mind that the comments about errors in the following steps refer only to the provided test code.

### TODO 1

Install CppCheck using default options. You can add pyhton functionality if you wish.

### TODO 2

Before contiuning, it must be noted that CppCheck runs locally, so you need the projects files to analyze in your computer. If you have them stored in the cloud, download them.

Once CppCheck has finished installating, open the cppcheckgui.exe located in C:/.../Users/User/Program files/CppCheck.

Create a folder where we will store our CppCheck files and the output of the analysis. You can create it in the desktop for availability during this tutorial. We'll call this folder bugtracking.

In the CppCheck menu, go to new project, choose our bugtracking folder as location and choose a name for your CppCheck file.

### TODO 3

A project configuration pop-up will appear.
Go to the first tab paths and defines.
There, choose import project and browse to your solution file (.sln) inside your Visual Studio project folder.
Make sure that analyze all Visual Studio configurations is checked.

### TODO 4

Go to the next tab Checking.
Select a build dir (the folder where our analysis results will be stored). This path is relative to the CppCheck project file folder which we have created in TODO 2.
Choose the target platform of the project.
Below, check all libraries your project uses or will use (most likely SDL and windows).

### TODO 5

On the next tab, Warning options, you can add excluded paths and errors.
You will most likely don't want third-party libraries to be checked for errors, so you can add their paths here now.
By now, we will not exclude any error so we can see all possible issues CppCheck can find.
Click Done on the project configuration tab. Accept if you are asked to create the build dir folder.

### TODO 6

Right when you end configuring your CppCheck files, the analysis will start.
Once finished, a list with all found errors will be displayed.
You can also access error files inside the build dir folder specified previously.
Before proceeding to check the errors, let's configure a bit more our CppCheck.

### TODO 7

Inside the CppCheck menu, go to Edit/preferences.
In General, check all options but Enable inline supressions.
In Reports, check both options.
Once finished, close the Preferences tab.

### TODO 8

CppCheck can use .cfg files to further configure the analysis.
Go to the folder where our CppCheck file is (TODO 2), create a new Text document and call it configuration.cfg
At the start of the file, write: <?xml version="1.0"?>

### TODO 9 

Open the CppCheck menu and go to View/Library Editor. There, go to Open and add the .cfg file we were editing.
There you can add functions by writing their name and argument number.
Then, double click in any argument to set the rules it must follow. Save once you have finished editing.
Remember to go to File/Edit Project -> Checking tab, and make sure the library "config" is checked to start using it.

### TODO 10

Let's check the results from the CppCheck analysis. If you are using the release test code, only a single bug is found related to a const attribute.
However, CppCheck does not find a memory leak that is ocurring in the code.
Let's try another SAC tool: install Visual Code Grapper from the release .zip file or download it from their website.

### TODO 11

Start the program, and make sure that the language in Settings is set to C/C++.
Go to File/New target directory and search the folder were the source files are located.
Press Scan/Full Scan to start the analysis.

### TODO 12

As you can see if you are using the test code, VCG has found a bug that CppCheck did not found: the memory leak.
It does also analyze comments in search of potential dangers.
However, we can also see that VCG has not found the const bug that CppCheck did before.
In fact, any of them has found a signed/unsigned mismatch bug in the test code.

## Conclusions 

Although they are a very useful tool for programmers, SAC programs are not always able to find all bugs, so we should always double check and manually review for errors.
Visual Studio integrated SAC offers quite good results while still being free to use.
Paid SAC tools can find several more bugs than free programs and allow to online features, so they are a good choice for greater companies.

## Resources

http://istqbexamcertification.com/what-is-static-analysis-tools-in-software-testing/
https://en.wikipedia.org/wiki/Static_program_analysis
https://cs.au.dk/~amoeller/spa/
http://cppcheck.sourceforge.net/#documentation
https://community.synopsys.com/s/

## Contact info

If you have any doubt about this tutorial or the SCA subject, please e-mail me at rodrigodpl97@gmail.com.
