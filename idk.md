# Programming patterns in main project

All program code files are in the repository(https://github.com/b0re3b/projectchechkers), also you can check general documentation to this program.

Using design patterns helps developers create more structured, flexible, and easily maintainable programs. Patterns provide standard solutions to common problems, avoiding ad-hoc solutions and improving code readability. They also help reduce dependencies between program components and enhance code reuse. Utilizing patterns reduces the risk of errors and simplifies component testing, while also improving system scalability.

## MVC(Model-View-Controller)
This program follows the Model-View-Controller (MVC) paradigm, which helps divide the program into three main components: model, view, and controller. The model is responsible for managing data and the business logic of the program. In my program, the model is represented by the classes Player, Piece, and Board, which represent players, pieces, and the game board, respectively. The GameLoop class manages the game state and interacts with other model objects.

Some functions are declared in the Board class due to the specifics of the SFML library, but their implementation occurs in other classes. Similarly, the view functions for displaying objects are declared in their respective classes but implemented in the drawobjects file. Overall, the program meets all requirements for separating models from their representation and the controller.

### Facade

In my program, I use the facade pattern to make it easier to understand and manage. For this, I've created a separate class `GameFacade`, which gathers all the components necessary to start the game. This allows me to avoid bulky and complex code in the main `main` file and provides greater structure to my code.

Instead of having detailed instructions for setting up players and other complex processes directly in the main file, I use `GameFacade`. This makes my main file less cluttered and more understandable.

Moreover, thanks to the Facade pattern, users can easily start the game without understanding all the details of the internal implementation. They simply create an instance of `GameFacade` and call the `runGame()` method, making the interaction with the program more enjoyable and understandable.

Thus, using the Facade pattern allows me to simplify the interaction with the program and provide a convenient interface for users.
#### State

In my program, I use the State pattern to manage different states of Piece objects without the need to change their interface. This allows me to replace the logic of handling states in the Piece object without changing the object itself.

When a piece transitions into different states, such as regular or king, it automatically changes its behavior according to the logic defined for that state. For example, if a piece becomes a king, it gains new movement and attack capabilities.

In my program, there are two classes, RegularState and KingState, representing different states of pieces. Each of these classes contains its own implementation of movement and attack methods according to the type of piece.

The Piece class contains a reference to an object of the PieceState class, representing the current state of the piece. When the state of the Piece object changes to RegularState or KingState, the invoked methods will automatically be delegated to the corresponding state classes.

This approach allows me to keep the logic of handling piece states separate from the Piece object itself, making the code more modular and convenient for extension.

After using the State pattern, the program became more flexible and supports easier extension. Now it's possible to add new states to pieces without changing the core logic of the Piece class. This enhances modularity and maintainability of the code.

Additionally, applying the State pattern simplifies working with object states. Now, when a piece changes its state, it automatically receives the corresponding movement and attack logic defined for that state. This makes the code more understandable and less error-prone.

Moreover, using the pattern allows leveraging the principle of polymorphism for handling different types of pieces, enhancing readability and expanding the program's capabilities.
### Observer

In my program, the Observer pattern is used to organize the observation of objects. When input data changes its state, a message is sent to the Board class, and then all other classes are notified. I use this pattern to ensure automatic game updates when the board state changes. For example, when a player makes a move, all other objects that display the game state are automatically updated to reflect the new board state.

The Subject class (or Observable) in my program is represented by a class responsible for the game or board state. It contains a list of observers and provides methods for attaching, detaching, and notifying observers of changes.

The Observer class defines the observer interface, which includes the update method. In my program, a specific observer is implemented to handle game updates.

When the game state changes, such as when a player makes a move, the Subject class (board) notifies all registered observers by calling their update method. This allows all objects that display the game state to automatically update and reflect the new state.
### Summary
Overall, working on the lab was interesting and made my program much more flexible, also improving its functionality. These patterns provided us with a better understanding of piece states (thanks to the State pattern), better awareness of the situation on the board (Observer pattern), improved visual perception of the main program file (Facade pattern), and made component separation in MVC work better.
