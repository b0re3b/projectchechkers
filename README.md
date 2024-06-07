# Main priject and threads

All program code files are in the repository(https://github.com/b0re3b/projectchechkers), also you can check previous documentation and compare it (https://b0re3b.github.io/projectchechkers/)

In this semester, I continued working on the project from the previous one, as it was unfinished, and the instructors pointed out objective shortcomings and weaknesses. Therefore, I set myself the goal to address all these points and significantly improve the program. The main changes in the program relate to architecture, task distribution, management, memory handling, improvement of functions and algorithms, and adding new features that overall enhance the program's functionality and make it more extensive.

## Components
I continue to work on a classic game of checkers with AI as a computer player. The main components of the program:

1. **Board**:
 - Represents the playing field where checkers are located.
 - Initializes the game with the initial layout of the checkers, processes the player input and draws on the window.
 - Has functionality to check the end of the game, process player input and highlight possible moves.

2. **Checkers (Piece)**:
 - Represent separate checkers on the board.
 - Contains information about their location, status (alive or killed) and color.

3. **Logic**:
 - Performs the basic logical operations of the game, such as checking the validity of a move and finding the best move using the Minimax algorithm enhanced alpha-beta algorithm.

4. **Menu**:
 - Displays a menu to select the player's color and game difficulty level (easy, medium, hard).

5. **Game**:
 - Handles the main game cycle, board display and player input processing.
 - Launched by the `GameFacade` external class, which initializes the game window and starts the game.

6. **GameFacade**:
 - Represents the main application interface, which controls the main loop of the game and interacts with other classes to start the game.

The program uses the SFML library to work with graphics and display the user interface. The user can choose his color and difficulty level before starting the game. The computer uses the improved Minimax algorithm to make the best decision about the best move.
## About thread

In my program, I use the thread library to optimize the execution time of the algorithm concurrently with the game process, so that the computer can make its move faster and the game can continue smoothly. When the program invokes the Minimax algorithm to find the best move, it creates a new thread object, MinimaxThread, and passes parameters to it for computation. Then this thread starts, and the Minimax algorithm begins its work in its own thread, without blocking the main execution thread of the program.

After the Minimax algorithm completes its computations in its thread, the result is passed back to the main thread using synchronization mechanisms, such as utilizing the join() method to wait for the thread to finish its work. Thus, the main thread can obtain the result of the Minimax algorithm's computations and continue executing the program, using this result to make decisions about the best move in the game.

So, in result we have:

Before using threads evaluation time = 557 microsecund and after = 191 ms.(screenshots with proof you can check in my repository)


## Project architecture 

Before I started reworking the project practically from scratch, I had a large, tangled piece of code that lacked logical structure, the use of design patterns, and other programming best practices. So for this project, I completely rebuilt the program. Now, we have each class in separate implementation and declaration files, and I used the Model-View-Controller (MVC) pattern to separate the logic, controller, view, and models. This separation was done in accordance with the requirements of the SFML library. All components are divided into separate implementation files, although some functions are declared within their classes because they are tightly bound to specific areas and cannot be detached.

The program is documented using Doxygen, and diagrams are created with PlantUML. Micro-benchmarking is performed using the built-in "chrono" library. Other resources are also utilized to enhance the program, making it better for both developers and users.


## Patterns 

Moving forward, the program is extensive and has many opportunities for development, so I could apply almost any programming pattern to it. I chose the following patterns: Facade, MVC, State, and Observer. Additionally, many other patterns are implicitly implemented in the program, such as Singleton, Strategy, and others. I focused on these four patterns because they significantly improved my program.

### Facade Pattern
This pattern helped me hide the program's startup process from users and other developers. In the class, we can find all the elements that launch this program. The role of this pattern has been fulfilled, making the program more modular and easier to understand.

### State Pattern
I used this pattern to represent the states of the pieces on the board. This was something my program was sorely lacking. Due to this deficiency, some functions could not correctly calculate move options and the overall board state. This pattern, like all the others, has played its role in organizing the code's modularity.

### Observer Pattern
This pattern is applied in the program to notify other components about changes in the board's state. We have an observer that signals other functions to adjust to the new game reality when events change. This pattern also significantly improved the program's modularity and functionality, making it work more cohesively as it now has all the necessary information about the game's progress.

## Changes in UML

In these diagrams, we can see only part of the changes that have taken place. Before the first lab session, I continued working on this project for the second semester, so a context menu had already been added, allowing users to choose the color of the pieces, and the program was divided into components. However, compared to what it used to be, the project has also undergone significant changes.

### Class diagram
In this class diagram, we can see that the number of classes has significantly increased. However, with this increase, we also notice that some classes have become smaller and more modular, which is very convenient for continuing to work with them.

<img src="https://www.plantuml.com/plantuml/png/rLTVRzms37-_J-6dm9TU7ZRioTY2va-w1aEs8Ccm1iCmw2pUMOqi6P9yIVRdkq-c9TcIBqxMjnPeA_v8aJzI8grxhmrHfgtvekH4w-oQasTGsT-BpFuvoYZRR5ZPSlDSP4mOXvQIIrLaUbCKPztImUQvWS9vkBDhXDyv84ythLBdsG_PDylNzgGnPhrimU2sV9cIHLsttwgcZBNJ2NYyI-9PyvraTF7lmXUCGGcXNjeG0qKFtdRhG-SIaPm9PXZXjnChorgqd3V6flZ0nBR8rb9oYsu8r-3pELVaCNzaWih7Fg4R41JKRuWSU6eX1tJT9J6D5zlMSeTsdx22gymkxzroBOcYHNRQ_PT48CQGyY4tHDbQ-gszDBSxAHtomVe59et5FTs3LVQbn18tNyxp1hOj9-ehOFeJ4zklWEQLt0M6AEJBiO0ZoVj5mRi5GJyDonuTDVijRioNY2Vm_GI-iCxsWTuovlkpfA7DiQe5mhxlIwaW6f4LurI1A6m2j2XsK1gfllUEZbr0B-U3mvNt5QVMLod4z9brffCSpbnigvYDJYX5qnp95e7DvBpm64Fo2cW_3_rSF72ADRUtPBzA0xSSWEBTkHGKdiR5mekbtStw_Tll_d04CMvkumLtgpv8a4SLkl6qycLG3zhJWTjKVzcFPVON_4XgoAS9hlRbbZG94qrhA37ahHFQQhPTk6K_xBqRZLKuCVcJk-dzTossgjYsulQloHjVKM_-OlJP5gV_uzCYcqOA40Q99ZHN_UFWJfvLK3wCFhi7SGAm8xmb1leZZecXez0XhOPhgPbXKkHr9_a9W8AR0Kd3ShbbPPWmDXIZH37pd8wmkHAVWkwxZa9Zgf1SRKyPbBi9Q9_KDMrI0OeOw22Tv3djJj-PPouCnfyvjPeymDHcDPfFiRrewpKekQcHJHDTvyDf7aE7NfpStlzvVd5zzt6CNbsSN_vwDSK_djoSJr5j-oiv9zjkOQY-V76TVipEGLLR4x5tuYGdbNOyzlbCf-npd9x-P0YfLkJJRns8zeqflaFZbsdvE6KbfGRtilKiugB-ijQWTiD3FZxQjx697AKtx5MIRKE9WKazqEa7KXBw-i4xTGsYBR0qdbTmaOzAtw7JS74XPdZTjklFK9f0IhgDEkvIx-_mUFmsgd9lNcJ18Xcmy3Ox8GtRFE-vHqomcZpTLGe83ImDYevYBymS-339741uKv4ni0OJoVlcNNW6w9QRyQoEAAONPZn5Xx0hZ3WpNFq1upCmZqlrMJAHGFMOmeTMbB4Utmd8UtZZnOKzEke_7ekUn23Z9yEAeryjY_4F0wlwvtYiz6_ngGQNNkNccPtLAFatsC8l1XFyrug-uN5u3Wv0j8aot7qB-_LYQ1uCPtSvnuTMZ7OLMKLqw8F1AhHAaMaGLFTNbfN4C2dquht5sfh_1m00" style="max-width:100%; height:auto;">

### Component

We can also see corresponding changes in the component diagram and others.

<img src="https://www.plantuml.com/plantuml/png/RP51JyCm38Nl_HNHxXF_04qWRGSe8CeDSV1IgmkqIPMc4mZnty5sgTDjFVbzptbI_JP3WfZ6hYrwi1_Ge5dje4Dp6xe-UFHfM9dlmlnzhyItOA76DmE3KIbsYNvaWmP1JoryOMGeemRD4O9k0iIQ6K-wzxWVC1wda1p8IZNktz4cTgTPZD9vry7doo4YIF22o58R6cVPv6bw6Ox8Z0P53w5MJ6BwHOSMgmH9J9LYFsCpjX1r8GUoSkTye_wiYfz2AwcsvVsbIeXVxIBq1sS7Va_a7r24jcJMwslfveIHlC3qqYUUD4H9BBbPMShiF83mt0xR-KC5KeBgHMFAkG6LMeYYh0OTsT7xdtbwU_sPnJatwEknQty1">

### Sequence

<img src="https://www.plantuml.com/plantuml/png/VPBFJlCm3C3lUGfhfqxgzm8zV9f0WXC22Lx0JSmQI9CgJRVrxI5_X9SESMaS-nSx_Ic7EQ0FosZ4zBrggIUq0NQFED83IbIq0vo1jpNsH7P9G0pgqel1bNmgvl1c0BUkItSElKgr5DsUU-vdygVI_3fHewzB_q4o9Ah4czjhgqUyl0sUC0-iCZLit57B1AL827O2__ud0HtunSPqinSeWpvXe6mcVYALJNGW1-TckdV6-MksYCeBTvMH4ugsNEbQAUZ0qhdAD7sqsC9PM-NEFAqsnviqEQll04D0EJIkLFXq1aJwHhu8_kj4GKHPVxcv2_fzRVPNlreHdETcYkeRLL9OHfF_lWKtJSwI3IqCouWsczn8IJ9OGbuQJwg5tg3ylB5G-FmoEZYXqGgz3cipQPBKmgM5bKzbZg_EYRhlraFPyxFw6SnliODZZBNLyq2gTicKE91LosY-0000">

### Object

<img src="https://www.plantuml.com/plantuml/png/NP1V3e8m38VVEGKNu0g6-A0FHYNY1SfeS6P_ah4HlRsnXBNioVRxTPL-xHmXn6HDvOStgbXt1huOjkuC5a-WOCIDND4baMP-z1166To76SF2g_f4ltcFTjh2v_aA2FcTyPDMUS8lAEkRvw_eD2hi8yHC7ZWb0s77BjfDAwZMi-gcESYRkAI4RcEMfqicpokprSD_4xNqlpGaOxc0y2Q7OlcG0RdXVY-GEQdYbiqn4lAuf4HAB3EMsQ8RapK_">

### Package

<img src="https://www.plantuml.com/plantuml/png/TP513e8m44Ntd88BS0L3NEX6b4GlCBPVh9QMJ0lH6EykeHgrrbc-dyxhp9JE4_k-rLb7uamDyegKgTcU87n-o_AnNicIMamebD3at0GJQ462v3jGneCF94AJbRLTzAQ2wITqpxwSSqiiOscW2Ujcxy03E8gqRPI8XNR0saf4-4-7Ma4WnRQU_4-WwGgEVSgebYwx8uDauY_FuSVnFmzG5BEmuHY63PGmShpT0m00">

## Summary

Overall, this project has changed almost completely, with only the original idea remaining from the old project. The program's functionality has also increased; we now have the ability to choose the difficulty level and player color through the menu. This is just the visible functionality; many functions within the program have either been renovated or added from scratch. Most of these changes are internal and become apparent upon careful code review. The program includes testing and has all the necessary source and header files for operation. 

Of course, this is not yet a fully finished project and it requires more time to become a complete checkers game program. However, the program performs quite well in gameplay and already has an architecture that allows for rapid further development thanks to its modularity. 

The TODO list should include increasing testing and debugging, further developing and improving the move selection algorithm for the computer, and moving away from SFML to more powerful graphics libraries or full-fledged game engines.
