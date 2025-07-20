#include <raylib.h>
#include <vector>
#include<string>

using namespace std;

// GAME COLORS :
Color red = {255,24,60,255};
Color blue = {4,154,255,255};
Color gray = {100,100,100,255};

// FOR GRID DRAWING
vector<Rectangle>  grid = {{225,80,10,350}, Rectangle{365,80,10,350},
Rectangle{110,180,380,10} ,Rectangle{110,180+140,380,10}};


/*-------------------------------------------------------------------
Objective -> the grids are assigned an initial value of 0,       
when the player 'X' presses a rectangle, it changes the specific 
index to 1 and if player is 'O' then index to 2;                 
------------------------------------------------------------------- */

//                              column 1:                   Column 2:                      column 3:
vector<Rectangle> grid_boxes = {Rectangle{112,88,110,90},     Rectangle{240,88,120,90},    Rectangle{380,88,120,90},
                                Rectangle{110,200,110,110},   Rectangle{240,200,120,115},  Rectangle{380,200,120,115},
                                Rectangle{110,335,110,100},   Rectangle{240,335,125,100},  Rectangle{380,335,125,100}};

char player_icon = 'O';

//                                            Column 1:         Column 2:
const vector<Vector2> player_icon_position = {Vector2{135,70}, Vector2{270,70}, Vector2{405,70},
                                              Vector2{135,190}, Vector2{270,190}, Vector2{405,190},
                                              Vector2{135,315}, Vector2{270,315}, Vector2{405,315}

};

int player_number = 2;
int game(void){

    if (player_number == 2) {player_number = 1 ; player_icon = 'X';}
    else {player_number = 2 ; player_icon = 'O';};

    int grid_state[] = {0,0,0,0,0,0,0,0,0};
    vector<int> which_index_is_not_zero;  

    vector<Vector2> text_pos = {};
    int move_count = 0;
    while (!WindowShouldClose())
    {
        Vector2 mousepos = GetMousePosition(); //getting mouse position -> checking which box is clicked upon
        BeginDrawing() ; 
        ClearBackground(WHITE);

        // RECTANGLE grid
        for(Rectangle i : grid) DrawRectangleRounded(i,50,10,gray);
        
        //THE MAIN GAME:
        for(int i = 0; i <= 8; i++)
        {
            DrawRectangleRec(grid_boxes.at(i), WHITE);

            if (CheckCollisionPointRec(mousepos,grid_boxes.at(i)) && 
                IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && 
                grid_boxes.size() > 1 && grid_state[i] == 0)
            {
                move_count += 1;
                grid_state[i] = player_number;
                
                //PLAYER ICON DRAWING: BASED ON WHICH index of grid state is not zero and if =/= 0 then what is the value of that.
                for (int i = 0; i <= 8; i++){
                    if (grid_state[i] != 0) which_index_is_not_zero.push_back(i);
                }

                /* 

                    0   1   2
                    3   4   5
                    6   7   8

                */
                if(((grid_state[0] == 1 && grid_state[1] == 1 && grid_state[2] == 1) || 
                    (grid_state[3] == 1 && grid_state[4] == 1 && grid_state[5] == 1) || 
                    (grid_state[8] == 1 && grid_state[7] == 1 && grid_state[6] == 1) || 
                    (grid_state[0] == 1 && grid_state[4] == 1 && grid_state[8] == 1) || 
                    (grid_state[2] == 1 && grid_state[4] == 1 && grid_state[6] == 1) ||
                    (grid_state[0] == 1 && grid_state[3] == 1 && grid_state[6] == 1) ||
                    (grid_state[1] == 1 && grid_state[4] == 1 && grid_state[7] == 1) ||
                    (grid_state[2] == 1 && grid_state[5] == 1 && grid_state[8] == 1)) && move_count <= 9){
                        return player_number;
                    }


                else if(((grid_state[0] == 2 && grid_state[1] == 2 && grid_state[2] == 2) || 
                    (grid_state[3] == 2 && grid_state[4] == 2 && grid_state[5] == 2) || 
                    (grid_state[8] == 2 && grid_state[7] == 2 && grid_state[6] == 2) || 
                    (grid_state[0] == 2 && grid_state[4] == 2 && grid_state[8] == 2) || 
                    (grid_state[2] == 2 && grid_state[4] == 2 && grid_state[6] == 2) ||
                    (grid_state[0] == 2 && grid_state[3] == 2 && grid_state[6] == 2) ||
                    (grid_state[1] == 2 && grid_state[4] == 2 && grid_state[7] == 2) ||
                    (grid_state[2] == 2 && grid_state[5] == 2 && grid_state[8] == 2)) && move_count <= 9){
                        return player_number;
                    }
                else if (move_count == 9){
                    player_icon = '!'; return player_number;
                }
                if (player_number == 2) {player_number = 1 ; player_icon = 'X';}
                else {player_number = 2 ; player_icon = 'O';};
                }
            }
            if (player_icon == 'X') DrawText("PLAY : X",192,450,50,red);
            else if (player_icon == 'O') DrawText("PLAY : O",192,450,50,blue);

            for (int i : which_index_is_not_zero){
                if (grid_state[i] == 1){
                    DrawText("x",player_icon_position.at(i).x,player_icon_position.at(i).y,120,red);
                }
                else if (grid_state[i] == 2) DrawText("o",player_icon_position.at(i).x,player_icon_position.at(i).y,120,blue);
            }
            
            EndDrawing();
        }
    return 0;    
}

int WinningScreen(){
    string Winner_text;
    Color winner_color;
    if (player_icon == 'X')
    {Winner_text = "    PLAYER X \nIS THE WINNNER !!"; winner_color = red;}
    else if (player_icon =='O') {Winner_text = "    PLAYER O \nIS THE WINNNER !!"; winner_color = blue;}
    else {Winner_text = "  ITS A DRAW !!"; winner_color = BLACK;}

    Rectangle button = Rectangle{600-100-30,385,95,95};
    const char* winner = Winner_text.c_str();
    while (!WindowShouldClose())
    {
        Vector2 mousepos = GetMousePosition(); //getting mouse position -> checking which box is clicked upon
        BeginDrawing() ; 
        ClearBackground(WHITE);
        DrawText(winner,50,180,60,winner_color);

        DrawRectangleRec(Rectangle{600-105-30,380,105,105},BLACK) ;DrawRectangleRec(Rectangle{600-100-30,385,95,95},LIGHTGRAY) ; 
        DrawText(" GO !",600-100-30+10,420,35,BLACK);
        if (CheckCollisionPointRec(mousepos,button) and IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) return 1;

        if(IsKeyPressed(KEY_R)) return 1;
        EndDrawing();
        }
    return 0;
}

int main()
{
    InitWindow(600,500,"TIC TAC TOE!");
    SetTargetFPS(144);

    while (true){
    game();
    int restart = WinningScreen();
    if (restart == 1) continue;
    else break;
    }

    CloseWindow();
    return 0;
}