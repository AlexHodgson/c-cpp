//Console based snake game
//@author Alex Hodgson
//@version 1 2020-09-26

#include <iostream>
#include <conio.h>

#include "snake.h"

using std::cout;
using std::cin;
using std::endl;
using std::fill_n;

const int WIDTH = 24;
const int HEIGHT = 24;
const int MAX_TAIL_LENGTH = 100; // End game if 100 fruits are eaten

int score;
bool game_over, playing;
enum e_direction{ STOP = 0, LEFT, RIGHT, UP, DOWN };


//Holds info on the snake and its tail
class SnakeHead
{

    private:
        int tail_length = 0;

    public:

        int x;
        int y;
        e_direction dir;
        int tail_x[MAX_TAIL_LENGTH]; // Could use vectors here instead? To allow playing beyond a preset score limit
        int tail_y[MAX_TAIL_LENGTH];

        void Reset()
        {
            Centre();
            tail_length = 0;
            fill_n(tail_x, MAX_TAIL_LENGTH, 0);
            fill_n(tail_y, MAX_TAIL_LENGTH, 0);
        }

        SnakeHead()
        {
            Reset();
        }

        void Centre()//Reposition snake head
        {
            x = WIDTH / 2;
            y = HEIGHT / 2;
            dir = STOP;
        }

        int get_tail_length()
        {
            return tail_length;
        }

        void AddTail() //Add to tail length
        {
            if (tail_length >= MAX_TAIL_LENGTH - 1)
            {
                game_over = true;
                cout << "Congratulations, max score reached!";
            }
            else
            {
                tail_length++;
            }
        }

        void MoveTail() //Move tail parts from back end to front
        {
            for (int i = tail_length; i >= 1; i--)
            {
                tail_x[i] = tail_x[i-1];
                tail_y[i] = tail_y[i-1];
            }

            tail_x[0] = x;
            tail_y[0] =y;
        }

};

SnakeHead snake;

//The fruit for the snake to eat
class Fruit
{

    public:
        int x;
        int y;

        Fruit()
        {
            Move();
        }

        void Eat()
        {
            score += 10;
            snake.AddTail();
            Move();

        }

        void Move()
        {
            x = 1 + (rand() % (WIDTH - 2));
            y = 1 + (rand() % (HEIGHT - 2));
        }

};

Fruit fruit;

//Sets the game state to begin playing
void Setup()
{
    score = 0;
    snake.Reset();
}

//Draw game in the console
void Draw()
{
    system("cls");

    for (int i = 0; i < WIDTH + 2; i++)
    {
        cout << "#";
    }

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (j == 0 || j == WIDTH - 1) //Walls
            {
                cout << "#";
            }
            else if (i == snake.y && j == snake.x) //Snake head
            {
                cout << "O";
            }
            else if (i == fruit.y && j == fruit.x) //Fruit
            {
                cout << "X";
            }
            else
            {
                bool printed = false;
                for (int k = snake.get_tail_length(); k >= 0; k--) //Snake tail
                {

                    int x = snake.tail_x[k];
                    int y = snake.tail_y[k];
                    if (x == j && snake.tail_y[k] == i)
                    {
                        cout << "o";
                        printed = true;
                    }
                }
                if (!printed) //Empty space 
                {
                    cout << " ";
                }
            }
        }

        cout << endl;
    }

    for (int i = 0; i < WIDTH; i++)
    {
        cout << "#";
    }

    cout << endl << "Score: " << score;
}

//Keyboard input to control game
void Input()
{
    if (_kbhit())
    {
        switch(_getch())
        {
        case 'a':
            if( snake.dir != RIGHT)
            {        
            snake.dir = LEFT;
            }
            break;
        case 's':
            if( snake.dir != UP)
            {        
            snake.dir = DOWN;
            }
            break;
        case 'd':
            if( snake.dir != LEFT)
            {
            snake.dir = RIGHT;
            }
            break;
        case 'w':
            if( snake.dir != DOWN)
            {
                snake.dir = UP;
            }
            break;
        case 'q':
            game_over = true;
            playing = false;
            break;
        case 'r':
            game_over = true;
            break;
        }
    }
}

//Runs game logic for current frame
void Logic()
{
    snake.MoveTail();

    //Move snake around
    switch (snake.dir)
    {
    case LEFT:
        snake.x--;
        break;
    case RIGHT:
        snake.x++;
        break;
    case UP:
        snake.y--;
        break;
    case DOWN:
        snake.y++;
        break;        
    default:
        break;
    }

    //End game on hitting own tail
    for (int i = 0; i < snake.get_tail_length(); i++)
    {
        if (snake.x == snake.tail_x[i] && snake.y == snake.tail_y[i])
        {
            game_over = true;
        }
    }
    //End game on hitting walls
    if (snake.x <= 0 || snake.x >= WIDTH - 1)
    {
        game_over = true;
    }
    if (snake.y <= 0 || snake.y >= HEIGHT)
    {
        game_over = true;
    }
    //Move fruit and add points!
    if (snake.x == fruit.x && snake.y == fruit.y)
    {
        fruit.Eat();
    }

}

//Runs the game loop
void PlayGame()
{

    Setup();
    //Wait for input before starting
    cout << endl << "Welcome to snake!, press g to start" << endl;
    cout << "Use 'wasd' to move the snake, 'r' to return to menu and 'q' to quit"<< endl;
    
    char input = getch();
    if(input == 'q')
    {
        game_over = true;
        playing = false;
    }
    else if(input == 'g') //Start game
    {
        snake.Centre();
        game_over = false;
    }
    else
    {
        game_over = true;
    }
    

    while (!game_over)
    {
        Draw();
        Input();
        Logic();
        _sleep(50);
    }

    _sleep(50);
}

int main()
{

    system("cls");
    playing = true;

    while (playing)
    {
        PlayGame();
    }

    cout << endl << "Exiting Game" << endl;
    return 0;
}