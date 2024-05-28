/**
 * @file main.cpp
 * @brief Implementation of a binomial heap visualization and interaction program.
 *
 * This program demonstrates the implementation of a binomial heap data structure using SFML
 * for visualization and user interaction. It allows users to insert elements into the heap,
 * extract the minimum element, get the minimum element, print the heap, and decrease the
 * key of a node.
 */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include "heaprealization.h" // Include your heap implementation

using namespace std;
using namespace sf;
/**
 * @brief Draw a node and its children recursively on the SFML render window.
 *
 * This function draws a node and its children recursively on the SFML render window,
 * representing the binomial heap visually.
 *
 * @param window The SFML render window to draw on.
 * @param node Pointer to the node to be drawn.
 * @param x The x-coordinate of the node's position.
 * @param y The y-coordinate of the node's position.
 * @param x_offset The horizontal offset between sibling nodes.
 */
void drawNode(RenderWindow& window, Node* node, float x, float y, float x_offset) {
    if (!node) return;

    CircleShape circle(20);
    circle.setFillColor(Color::Green);
    circle.setPosition(x, y);

    Text text;
    Font font;
    font.loadFromFile("//Users/bogdanresetko/Desktop/projects2024/binomial heapArialMT.ttf"); // Ensure you have a valid font file in the same directory
    text.setFont(font);
    text.setString(to_string(static_cast<int>(node->value)));
    text.setCharacterSize(14);
    text.setFillColor(Color::Black);
    text.setPosition(x + 10, y + 5);

    window.draw(circle);
    window.draw(text);

    float new_x = x - x_offset / 2;
    float new_y = y + 50;

    for (auto child : node->children) {
        Vertex line[] = {
                Vertex(Vector2f(x + 20, y + 20)),
                Vertex(Vector2f(new_x + 20, new_y + 20))
        };
        window.draw(line, 2, Lines);
        drawNode(window, child, new_x, new_y, x_offset / 2);
        new_x += x_offset;
    }
}
/**
 * @brief Draw the entire binomial heap on the SFML render window.
 *
 * This function draws the entire binomial heap on the SFML render window by iterating
 * through each tree in the heap and calling drawNode() for each tree.
 *
 * @param window The SFML render window to draw on.
 * @param heap Pointer to the binomial heap to be drawn.
 */
void drawHeap(RenderWindow& window, BinomialHeap* heap) {
    float x = 50;
    float y = 50;
    float x_offset = 400;

    for (auto tree : heap->trees) {
        drawNode(window, tree, x, y, x_offset);
        x += x_offset;
    }
}
/**
 * @brief Main function of the program.
 *
 * This function initializes the SFML render window, creates an instance of the binomial heap,
 * and handles user input for inserting elements, getting the minimum element, extracting the
 * minimum element, and printing the heap.
 */
int main() {
    RenderWindow window(VideoMode(800, 600), "Binomial Heap");

    BinomialHeap* heap = BinomialHeapSingleton::getInstance();

    Font font;
    if (!font.loadFromFile("/Users/bogdanresetko/Desktop/projects2024/binomial heap/ArialMT.ttf")) {
        cout << "Could not load font" << endl;
        return -1;
    }

    Text insertText("Insert: ", font, 20);
    insertText.setPosition(10, 10);
    insertText.setFillColor(Color::White);

    Text inputText("", font, 20);
    inputText.setPosition(100, 10);
    inputText.setFillColor(Color::White);

    string input;
    bool inserting = false;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::TextEntered) {
                if (inserting && event.text.unicode >= '0' && event.text.unicode <= '9') {
                    input += static_cast<char>(event.text.unicode);
                    inputText.setString(input);
                }
                if (inserting && event.text.unicode == '\b' && !input.empty()) {
                    input.pop_back();
                    inputText.setString(input);
                }
                if (inserting && event.text.unicode == '\r') {
                    double value = stod(input);
                    heap->insert(value);
                    input = "";
                    inputText.setString(input);
                    inserting = false;
                }
            }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::I) {
                    inserting = true;
                    input = "";
                    inputText.setString(input);
                }
                if (event.key.code == Keyboard::M) {
                    if (!heap->is_empty()) {
                        cout << "Minimum value: " << heap->get_min() << endl;
                    } else {
                        cout << "Heap is empty" << endl;
                    }
                }
                if (event.key.code == Keyboard::E) {
                    if (!heap->is_empty()) {
                        cout << "Extracted min value: " << heap->extract_min() << endl;
                    } else {
                        cout << "Heap is empty" << endl;
                    }
                }
                if (event.key.code == Keyboard::P) {
                    if (!heap->is_empty()) {
                        heap->print();
                    } else {
                        cout << "Heap is empty" << endl;
                    }
                }
            }
        }

        window.clear();

        window.draw(insertText);
        window.draw(inputText);

        drawHeap(window, heap);

        window.display();
    }

    return 0;
}
