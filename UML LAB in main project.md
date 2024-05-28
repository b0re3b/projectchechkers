# UML LAB in main project

All program code files are in the repository(https://github.com/b0re3b/projectchechkers), also you can check 



## Components

### Board

The `Board` class is responsible for managing the game state, including the positions of pieces, handling user input, drawing the board and pieces, and implementing the game logic such as move validation, highlighting possible moves, and checking for the endgame condition. It also contains methods for evaluating the board state and generating possible moves for the AI.

#### Key Methods

- `InitializeGame`: Sets up the initial positions of the pieces on the board.
- `validarity`: Checks if a move is valid.
- `inputdata`: Handles user input for selecting and moving pieces.
- `highlight`: Highlights possible moves for a selected piece.
- `numberofmoves`: Returns the number of possible moves for a player.
- `endgame`: Checks if the game has ended.
- `draw`: Draws the board and pieces on the window.
- `evaluateBoard`: Evaluates the board state for the AI.
- `MinMaxTree`: Generates the Minimax tree for the AI.
- `BestMove`: Finds the best move for the AI using the Minimax algorithm.
- `opponentPiece`: Checks if a piece belongs to the opponent.
- `generateMoves`: Generates all possible moves for the current player.
- `minimax`: Minimax algorithm implementation.
- `ComputerMove`: Makes a move for the computer player.
- `MousePosition`: Gets the index of a piece based on mouse position.
- `makeMove`: Makes a move on the board.

### Piece

The `Piece` class represents a single piece on the board. It includes attributes like `isAlive`, `isKing`, `color`, `x`, and `y` to store the piece's state and position. The `Draw` method renders the piece on the window.

### Player

The `Player` class represents a player in the game. It has attributes for the player's color and type (human or computer).

### Move

The `Move` class represents a move in the game, storing the start and end positions of a piece.

### MoveNode

The `MoveNode` class is used in the Minimax algorithm to represent nodes in the Minimax tree. Each node contains a move, a score, and a list of child nodes.

### Menu

The `Menu` class handles the user interface for choosing the player's color at the beginning of the game. It displays text options for "Red" and "Black" and returns the selected color.

### Game

The `Game` class manages the main game loop, initializing the board and players, and running the game until it ends.

## How It Works

1. **Initialization**: 
2. **Menu**: The `Menu` class displays a menu for the player to choose their color.
3. **Game Loop**: The `Game` class runs the main game loop, which handles drawing the board, processing user input, and making moves.
4. **User Input**: The `inputdata` method in the `Board` class processes user input for selecting and moving pieces. It highlights possible moves and validates the selected move.
5. **AI Move**: When it's the computer's turn, the `ComputerMove` method in the `Board` class generates the best move using the Minimax algorithm and makes the move.
6. **Endgame**: The game continues until an endgame condition is met (one player has no pieces left or no valid moves).

## Building and Running

To build and run the program, ensure you have SFML installed and set up correctly. Use a build system like CMake to compile the code. 

## Testing
The program contains unit tests that cover part of the functionality, namely checking the validity of the move, algorithm and computer moves and input data
## UML
UML stands for Unified Modeling Language. It's a standardized general-purpose modeling language in the field of software engineering. UML provides a way to visualize a system's design through a variety of diagrams such as class diagrams, sequence diagrams, use case diagrams, and more.
## Use case
This diagram illustrates the interaction flow between a human player, a computer player, and the game system in a checkers-like game. It outlines the sequence of actions and decisions taken by both players during gameplay. Each use case represents a specific action or event within the game, such as starting the game, choosing colors, selecting pieces, making moves, and checking for game over conditions. Overall, the diagram provides a structured overview of the game's main interactions and processes.
<img src="https://www.plantuml.com/plantuml/png/RO_BQiCm44Nt-eh1-owQXmDTb80MTHUXWj0F69IXDT6Zw15eI_-zazWMieatHdFE7URkOyAGiZK2TV81cYvRTA0CVbDe02DqQaBIsw-SADHKAY42wOJkmn0qBsYfWLy1_EL86YCFNrsVUZJz3y70EVSk7-UI_FIU_z8R7qPZDJUEP4WdK3tfQSTwRXpmJ73mbmblvhX3Tp8qNbzxsxjUgLkPxV9eqkTRANYxq7JtJlm9qIbuUBxMX2Su9WpfffNnYiTrvGBM3Egc1MmOb8A2tyDuosCLlAOO1oBa66WNWRRiMGHuoO1sZ1QLIkukt9CxPMl-0G00">

## Class diagram
This diagram depicts the structure and interactions within a checkers-like game software system. It consists of several classes representing different components of the game, such as the game itself, the menu, the board, player, pieces, moves, and move nodes.The "Game" class manages the core gameplay loop and interactions between the players and the board. It contains references to the board, human player, computer player, and the SFML render window. The "Menu" class handles the menu interface for player color selection.The "Board" class represents the game board and contains the pieces. It provides functions for selecting and validating moves, updating the board, checking for game over conditions, generating moves, and more. The "Piece" class represents individual pieces on the board and provides functionality to draw them on the screen.The "Player" class defines players in the game, specifying their color and type (human or computer). The "Move" class represents a move in the game, storing starting and ending coordinates. The "MoveNode" class is used in the minimax algorithm for move evaluation.The diagram shows the relationships between these classes, such as how the game uses the menu and board, how the board contains pieces and uses moves, and how players make moves.
<img src="https://www.plantuml.com/plantuml/png/ZLLDRnCn4BtdL_Y4jf1S4ASzeBO10KA12YhHgEh1NKyJgrvxvO-q4UA_invFNBiBWKfrx7apy-QD9ywfyzpwqAjPfxXpx0FlWVsSiV5lmSuDjuBTnfKi5uhlmR9jwBbE-nheJ3y43xR2t5tRVWCjmFwGMfW7ze0VYBv2nYPPsedhYtd9rHBDQAs9Cd12IMtGpKdBTaQAsQyPQLk13bdRXAcg2dt_MbMcwRR6E5WQPMoa8zMP4FkN6IyaTC26kBhhrszkA8S31Pr7i7bicTH-plRuIGB8RyUL5Dp3cHOhVWyhiuDcgDJFsR7uCCHeBAaX9Ak0xZvUmzSTe8vROnHX6z1WkKSw5x6ukJxKtXyAwSSbONNghTnirVZl6zJzIGiur7Zaod7YsjI-Ef_KG_2Z3dxaRgg04Td40QjLmOwhaBjHqM5rXo6GUiKVBor0vJDd0WQ_HS_9928DzUcB4K2fpi5vxDH_XbAO6GQZGK_7W-ALiPTc6UylTG97iTQgGtyBrjprU8FrnBoivPhWuC8uwQNHJHzFLyI4XpKUA2GFEPQMXpmIC-a-IxsfBMTAagf5Z6UFnNvF-wmWAQEotbd-yC_hplMGibnGdRD-hYxt0p0_Bec9h0qwblqy3iynHLlaF0HimEUt8Rl7Ia67ll2dOZ_6bmvtIngCh2hE1BbHp_3TldfkM1S6qEAgFgwfBXp4a_A0mNJPb8aECSlJDbaBVTyniA6XgCthYVdzcEnFnkoPzTBN9sj60uipN4hkZALp3hY-OTrMAc514mKXvICrJw7FnQI-99T2ItITLBqa4l8dRiAv48WtMCgJGp6i-4ExME0FJSk20yVUPYC-CnFhuPdeZFRMg0YX8s8IEaWGbxg4a3pdGZ-oelwTKRk4OFOCuTiUxV54LjIGKvs25g5Nlm40">

## Component diagram

This diagram represents the components of a checkers game software system. It includes various modules such as the game application itself, menu, board, player, piece, move, and move node.

The "Game Application" artifact serves as the main application of the checkers game. It utilizes the "Menu" module for managing user interface interactions, the "Board" module for controlling the game board, and the "Player" module for managing player actions.

The "Board" module contains the game board and interacts with the "Piece" module, which represents individual pieces on the board. Additionally, the "Board" module utilizes the "Move" module for managing moves made during the game.

The "Player" module controls the actions of the players in the game and utilizes the "Move" module for making moves on the board.

Lastly, the "Move" module interacts with the "MoveNode" module, which is used for move evaluation and decision-making processes within the game.

Overall, this diagram provides an overview of the components and their interactions within the checkers game software system.
<img src="https://www.plantuml.com/plantuml/png/XP1Bgi9044NdlOeY2yW27Y7awS2HubmoA3gbDkbFw4z0nBtRCHKme9XHNSv9tQAR4D77PBGOKFPu8IYsLv8z-G0xD5J0NK3-JbE0_s7GIc9KphPGLUYZEgECTJqxUxAfdSUDGz_nVDHu8xy4HP9QzjtuFXvSb-D3Y0zbPLdpVlY352XyaxZvbyKtPKqw6xtJGV2VByvdCaPbLvWlNpfONXDbHwV7YNBL6XliC-F8X5zWMTkGxPBHJm00">

## Object
The diagram depicts the structural composition and interconnections among different components within a game software system. It outlines the relationships between key entities such as the Game, Board, HumanPlayer, ComputerPlayer, Piece, Menu, and RenderWindow. These entities interact and collaborate to facilitate the functionality and operation of the game application.
<img src="https://www.plantuml.com/plantuml/png/LP2n3W8X44Hxle8Vu0UiBbfeOtAniLwvZS70OlQM6FrwzuBSIJVCm9i9mop0Kb8q9jyUwCKU8M7J-mmyjSEf9A0nmXkvMOUSdaMGUtSCw5V46QaqVK6QaA-1flmoPYcopjKIkxC-at2ESml-2pLM3NTSqwwxkr1vpjKTFp04sfukczGl4cBuRCXkd-Q150zUPcC6JPPF-W80">

## Composite Structure

This diagram illustrates the internal structure of a game system, organized into a package named "Game." Within this package, there are several components: Game, Board, Players, Menu, and RenderWindow. The Board component contains a sub-component Square, which represents the grid of squares on the game board. The Players component further contains two sub-components: HumanPlayer and ComputerPlayer. The Game component interacts with the RenderWindow component for displaying the game interface.
<img src="https://www.plantuml.com/plantuml/png/SoWkIImgAStDuIf8JCvEJ4zLK79Fp4rLKgZcKW22vFpSWloyrBmI1P0eL11LmYa_iIW5AeCfgnHSM9fOb1fj4Gj4IWg9nGeG0RZoMYn61kGaLgOM5UCqrACqDp4FeWY72cSWgxGajGYY2AzblgbvfLY4WrBpKbABmZFpKlBBkI1wQxcuGA6W1_6nBjGdA68mfqC4OVxGXLW23a9TL9CTW1nWw0C0">

## Deployment

This diagram depicts a software architecture where the "Game Application" artifact resides on the "User Machine" node. Within the "Game Application," there are several components: Game, Menu, Board, Player, Piece, Move, and MoveNode. The relationships between these components are shown with arrows indicating their interactions. For instance, Game uses Menu and Board, while Board contains Piece and uses Move. Similarly, Piece involves Move, and Player makes Move, and Move uses MoveNode.
<img src="https://www.plantuml.com/plantuml/png/TP1DIWGn48NtVOgY3p07S26Z6rSjRbp9B8gan61IDUIdGMJkReyywH2Px5vzN_6A74lbN5kAaveNcb-BP5hOVGILcRudsjucX7TsbUOdJa8FvtCCZcim_JNmtgxmH7jUHDjfZu_6sNVv9VANv7uGn4cN5rl7-6mUeylKTHuEzwYZEsf5oWXHVelYb0qxqvejGi7MrS5rK3ZeFmK7TnrO6cZGrU8A0zM3alWJ72DGVC1VnMKwYlgMuWy0">

## Package diagram

This diagram illustrates the component structure of a game application. It's organized into different packages: "Game," "Components," and "Players." 

The "Components" package includes classes such as Game, Board, Piece, Move, and MoveNode, representing various elements of the game logic.

The "Players" package contains the Player class and the PlayerType enumeration, distinguishing between human and computer players.

Outside the packages, there are two standalone classes: Menu and RenderWindow.

The arrows indicate dependencies and relationships between the components. For example, the Game component depends on both Components and Players, while Game.Components encompasses all the internal components. Additionally, the Game component uses Menu and interacts with the RenderWindow class.
<img src="https://www.plantuml.com/plantuml/png/RP3D2i8m48JlUOhGUtq4ANhGYr94yBmqYnJpK_AZ5Ecxsqr3RKFtKDXlfiDaA-V1-g0aww1vmHDvSGA51VyoFiuCZqPrHgFsBabn6WdESVeXGmS3LcIiRh79VHVpta9N8oOynE-wIYsXHxlHOn9cY3genEvzXsHVp3aeq2j2Jmn-4J3a5LB1CNYntb0Bj8zM2_DX0sDqZTt_NBmizpoor7lJG9bHe6qTMOrBKF87">

## Sequence diagram

It shows the sequence of interactions and message exchanges between different components or actors within the system during a specific scenario or use case. This includes how various elements of the system collaborate to achieve a particular functionality or behavior. The goal is to provide a clear understanding of the flow of control and data within the system, highlighting the order in which actions are performed and how they affect the system's state.
<img src="https://www.plantuml.com/plantuml/png/bLB1RkiW4Bpp5HnjAUy7V7XAuqDzgMefKjKU2LubA1XRWDtcxyl2DZXELAaveB2pCxFUOUkyi7xgDHFI3vOtKozCgyK5B1UEDotLww4V9mysGtNBna1LKet2UFuiUhWfx0PXkvjAgq3UzhmCCp26LFxlVs9KF4w4jQ9aiOGOtYj-3ESUOUW2o9esGr8hUOuEnTU6NyexLT0WVMvOQCTYnPLxqcf6Lom4RYPxEy5wbX6RzgYAqyJRev7m4nzFr0SapUD89TusV3KUjSz2gqvuGC5V6UIV3DwGLKHkoOHEA-VA9Jd6m-zgX5353Npov86BVj-aF3x8939M7pADE1TUC1NG3gukof3FWjMqrKyTsv1YklmAwW1BUcs4r-t2xGW6BEt1vIT2J34BfSL14zpZIG99-JGC3dRWF3PaV9cBE4C43zHLiZ-jQFrGSivhGMfPRn1pIjjwdS7o-WJod9FAB8a0_iMsOXbDsdBMIA7KW_7AJ13hTv58Gh56cMp3CVNw6m00">

## Activity diagram

The activity diagram illustrates the sequential flow of actions within a game application, guiding from initialization to completion. It commences with the game initialization, proceeds through player interaction, and concludes upon game termination.

At the outset, the game initializes its components, displaying the menu for player interaction. Upon selection of a preferred color, the game enters the main loop, alternating between the human player's turn and the computer player's turn.
<img src="https://www.plantuml.com/plantuml/png/bPBDRi8m48Jl-nGhJl0AS2WYIBHIQP7wSxTWKAmwNijsGBJgkzUoQ9mc1zGvPIUpkzbFMOQeV6mRG_c1QFvWTTJAw4_mHZLOq7ojWpFgmblODfLLBHB0bHZn2oANsbA7M9waFFXHn4tuYpZ9mq55uglcQw_El1Bb3ujYthUDihnB6-3vjVMsl2kX5nZi8-yqzkZrlYkZ3og2jtBg-sykkzTLnQzgx3_oNVnyWYyT-iZJphwRSQnXUNf1c17trB4OZyWAKLndm0JmrCfWH2MDQoFyyEIYl_aDBFplZQ6VB5nM2770OCnXlECsbt-mkSLdmAW8zg2FDAYwluVFjJQuVi6Jn3nrHjz4UT0ovTl6_000">

## Interaction Overview diagram

The diagram depicts the interaction flow in a checkers game. It begins with the human player choosing a color. The game initializes, and a loop starts, handling player turns and moves. The process repeats until the game ends. After each move, the results are displayed.

<img src="https://www.plantuml.com/plantuml/png/dP71QiCm38RlVWhH-rvWXz756saF6M65zQmbWXeKAyHsk-xfPukjIplMGmE1vF_qI_hHCaISOXhOO1TbWiKg3UYXPJpIj00Ci6f_a9LXJ96cERMj6NC3rxaHVOH5ZGCfgC_rId3g5LJde7NKaOABJWtvf7fZpAg5kmTeu1xiJYGGM66PJ5FKEgkR4WBAR5CNhShQshleaDqdWGutB3B2TkUOj1Ai-EXyec0WFpf2ZHjYwYBeOeggJ38lQ2S7Q2K4zyu4ZUp_c7K_HPVUDsJNOvmnvAW_yCWi1-fLF3SzVr2NvXxYx-xm8l6ASUttPTxCwFlVXMmfEPtpL6Elnx2tnB2tnh3_nYYldlarVz6qTRwNGov-Sc5aF6Ov98x1B3DE0ty1">

## State diagram

This diagram illustrates the states and transitions in a checkers game. It begins in the "Idle" state, waiting for players. When the game starts, it initializes and transitions to the "PlayerTurn" state. In this state, the human player takes their turn, validates their move, updates the board, and checks if the game is over. If not, it switches to the computer player's turn. The computer generates and executes its move, followed by updating the board and checking for game over. The process continues until the game ends, leading to the "GameOver" state.
<img src="https://www.plantuml.com/plantuml/png/rPA_Rl8m4C1tFuM_wGiLl013XK0gPK15wfyELGVNEOKeJe9i1vLMl7jzXwt4LjgXMnaYv-xtEywNMnWhjErgnLwkNlbiTiqtkGB6NDW2dVadu-uNqi-Yj6LJtBHwfyG9j65dneWZkN5PeSeFM8iQ-9nJUJnd4nOdYR_KUEXquzZ2HU-HXzpHleMUI1gvxMhHHFw-Z_mttBeW2Ic8yfDh8tVbj-qHkvIgbDMk10dP-vIV9kZ534fu80Zl1GgaJPMUGFxnWFgo5JftHXrosSM5dDwclDU70XPOxK5MEAkx8sXNeklpE21KQ4WnwESqdDN6X6H83K943FwbyCTiCWwFZVvV8ftfIO-uDxfMMnyw2_gx2hXHVIvIF2pzQ_on_SP4RBmp8RM61hJ_j0YC9Y9ZjMzR4zQb6536tpW54tyhgc1B8fPWB0PYFN2Z2-HJsPjN_zJI-1l-RcD-sfG8nDxdr1UdnXVGv5sjlW00">

## Changes
Some changes have already been implemented here regarding the project in the first semester, but as I continue to work with this project, I plan to break the board class into simpler ones, make more unit tests and improve the operation of the program.