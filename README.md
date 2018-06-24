link to the [research's web](https://rodrigodpl.github.io/Static-Code-Analysis/)

___

In this tutorial, I will explain what a static code analysis tool is and how to use it in your own projects, as it provides several benefits including computerized code revision.

I am [Rodrigo De Pedro](https://www.linkedin.com/in/rodrigo-de-pedro-60502b163/), student of the [Bachelor’s Degree in Video Games by UPC at CITM](<https://www.citm.upc.edu/ing/estudis/graus-videojocs/>). This content is generated for the second year’s subject Project 2, under supervision of lecturer [Ricard Pillosu](<https://es.linkedin.com/in/ricardpillosu>) .

If you wish to contact me for any question about the topic, you can find my email at the bottom of this page.           
       
___
      

## What is static code analysis?

- **Static**: not executed in runtime, unlike *dynamic code analysis*.       
- **Code**: referent to a program, a set of them, or an entire system.       
- **Analysis**: search for problems and possible improvements.       

An SCA tool will look for errors on a specific set of code before the execution.

## What are it's uses?

- Identify anomalies or flaws in the code.    
- Calculate performance metrics.      
- Ensure code security against hack attempts.     
- Analyze structures and dependencies.  
- Track contributors code quality and error rate.
- Provide accurate and meaningful error descriptions.     

## How does it work?

In the following link you can watch an informative video about Coverity, an online SCA tool. The functionality described in the video can be extrapolated to most current SCA tools in the market, so it's worth the watch.

[Video tutorial about SCA online tools](https://community.synopsys.com/s/article/Coverity-Tutorial-Introduction-to-Coverity)        
*Credits to Coverity developers for creating and sharing the video*

The summary of the ideas of the video would be:

 - First, the program scans all possible paths in your code flow.
 - Then, it creates a dependecy graph and analyzes it looking for errors.
 - Lastly, this data is sent to a server to be distributed to other contributors.
 
 
## SCA tools (online)

The main benefit of online tools comes when used in sync with a code storage service (Git, Bitbucket), allowing to automatic and continuous evaluation of the code written by all team members.      
Some online SCA tools are:     
1. **Coverity** ( Paid/ integrated with Git/ supports Java, C++, C# Python and Ruby)        
2. **QonCAT** (Paid/ supports multiple languages / quality analysis and metrics)       

# Coverity

Pros:
- online functionality
- reference in this topic
- performance and reliability
- supports almost any language

Cons:
- only free for open source projects


## SCA tools (offline)

Most commonly used compilers, as Visual Studio, feature their own SCA tool.       
However, dedicated SCA programs can provide better performance, support more programming languages or display better error definitions.      
Some offline SCA tools are:         
1. **CodeSonar** ( Paid / Static and binary analysis / analysis of third-party code included)     
2. **CheckMark products** ( Paid / lots of features / dedicated products / supports +20 languages)      
3. **CppCheck** ( Free / we will check it later )     

# CppCheck

Pros:     
- Completely free
- Highly-customizable
- Can analyze non-standard code
- Visual Studio plug-in [here](https://marketplace.visualstudio.com/items?itemName=Alexium.Cppcheckadd-in)      


Cons:        
- Rudimentary, few features     
- False positives

____

# Tutorial

Next, it's provided a brief tutorial so readers can easily implement SCA tools into their projects.
Each step of the tutorial will be named as TODO X.

## Release files

It is worth commenting that in this research's github repository you can find some useful files for the tutorial. You can download:
 
- SCA Research Full Code: some sample code to test SCA tools functionality. In this .zip the errors are commented.
- SCA Research Exercises: the same code, as above, but errors are not commented. 
- SCA Research Docs: the content of the web in .md and .ppt files to follow it without internet connection.
- CppCheck + VCG: the program of CppCheck and Visual Code Grepper.

#### TODO 0

First, we must download the necessary files. The installation files for CppCheck and Visual Code Grepper can be found in their respective websites:        
[CppCheck](http://cppcheck.sourceforge.net/)         
[VGC](https://sourceforge.net/projects/visualcodegrepp/)      

Alternatively, they are included in the release tab of the Github repository linked to this web, which also contains a small test program to chech SCA functionality. You can use any project you wish to analyze, yet it must be kept in mind that the comments about errors in the following steps refer only to the provided test code.

#### TODO 1

Install CppCheck using default options. You can add python functionality if you wish.

#### TODO 2

Before continuing, it must be noted that CppCheck runs locally, so you need the projects files to analyze in your computer. If you have them stored in the cloud, download them.       

1. Once CppCheck has finished installating, open the cppcheckgui.exe located in ../Users/YourUsername/Program files/CppCheck.     

2. Create a folder where we will store our CppCheck files and the output of the analysis. You can create it in the desktop for availability during this tutorial. We'll call this folder *bugtracking*.       

3. In the CppCheck menu, go to **New Project**, select the bugtracking folder as location and choose a name for your CppCheck file.     

#### TODO 3

A project configuration pop-up will appear.

1. Go to the first tab **paths and defines**.

2. There, select **Import Project** and browse to your solution file (.sln) inside your Visual Studio project folder.

3. Make sure that **analyze all Visual Studio configurations** is checked.

#### TODO 4

Go to the next tab **Checking**.

1. Select a *build dir* (the folder where our analysis results will be stored). This path is relative to the CppCheck project file folder which we have created in TODO 2.

2. Select the target platform of the project.

3. Below, check all libraries your project uses or will use (most likely SDL and windows if you are running Windows OS).

#### TODO 5

On the next tab, **Warning options**, you can add excluded paths and errors.

1. You will most likely don't want third-party libraries to be checked for errors, so you can add their paths here now.

2. By now, we will not exclude any error so we can see all possible issues CppCheck can find.

3. Click **Done** on the project configuration tab. Accept if you are asked to create the build dir folder.

#### TODO 6

Right when you end configuring your CppCheck files, the analysis will start.

Once finished, a list with all found errors will be displayed.

You can also access error files inside the build dir folder specified previously.

Before proceeding to check the errors, let's configure a bit more our CppCheck.

#### TODO 7

Inside the CppCheck menu, go to **Edit/preferences**.

1. In **General**, check all options but **Enable inline supressions**.

2. In **Reports**, check both options.

Once finished, close the **Preferences** tab.

#### TODO 8

CppCheck can use .cfg files to further configure the analysis.

1. Go to the folder where our CppCheck file is (TODO 2), create a new Text document and call it *configuration.cfg*

2. At the start of the file, write: `<?xml version="1.0"?>`

#### TODO 9 

Open the CppCheck menu and go to **View/Library Editor**. There, go to Open and add the .cfg file we were editing.

There you can add functions by writing their name and argument number.

Then, double click in any argument to set the rules it must follow. Save once you have finished editing.

Remember to go to **File/Edit Project -> Checking** tab, and make sure the library *configuration* is checked to start using it.

#### TODO 10

Let's check the results from the CppCheck analysis. 
If you are using the release test code, only a single bug is found related to a const attribute of the three purposely introduced into the code.

Now, let's try another SCA tool: install Visual Code Grapper from the release .zip file or download it from their website.

#### TODO 11

Execute the program, and make sure that the language in Settings is set to the language you are using (C++ if you are using the sample code).

1. Go to **File/New target** directory and search the folder where your source files are located.

2. Press **Scan/Full Scan** to start the analysis.

#### TODO 12

If you are using the test code, you will see VCG has found a bug that CppCheck did not, a memory leak. However, we can also see that VCG has not found the const error that CppCheck did before. In fact, none of them has found a signed/unsigned mismatch.

If you are, instead, using your own code, you are likely to have found as well different bugs using CppCheck and VCG.

____

## Conclusions 

- Although human revision cannot be obviated, SCA tools are very useful as support for QA in any development stage.
- Keep in mind the quality of the integrated SCA of the development environment you use.
- If you are working in an open source project, you can find reliable and free SCA tools.

## Resources

- [SCA definition](http://istqbexamcertification.com/what-is-static-analysis-tools-in-software-testing/)
- [Detailed research about SCA](https://cs.au.dk/~amoeller/spa/)
- [CppCheck documentation](http://cppcheck.sourceforge.net/#documentation)
- [Coverity SCA information page](https://community.synopsys.com/s/)

## Contact info

If you have any doubt about this tutorial or the SCA subject, please e-mail me at rodrigodpl97@gmail.com.
