#include <iostream>

using namespace std;

int main()
{
    const int num_of_players = 4;
    int score[num_of_players];
    int previous_throw[num_of_players];
    bool is_ready[num_of_players];
    bool end_of_game = false;
    int board_size;
    cin >> board_size;

    int i = 0;
    
    for (int j = 0; j < num_of_players; j++)
    {
        score[j] = 0;
        previous_throw[j] = 0;
        is_ready[j] = false;
    }

    while (!end_of_game)
    {
        char instruction;
        cin >> instruction;
        switch(instruction)
        {
            if (i >= 4)
            {
                i = 0;
            }

            case 'M':
            {
                int number;
                cin >> number;
                if (is_ready[i])
                {
                    score[i] += number;
                    if (score[i] >= board_size)
                    {
                        cout << "END OF GAME";
                        end_of_game = true;
                    }
                   
                }
                else if (number == 6 && previous_throw[i] == 1)
                {
                    is_ready[i] = true;
                    
                }
                previous_throw[i] = number;
                i++;
                break;
            }
            case 'P':
            {
                i = 0;
                for (auto sc : score)
                {
                    cout << sc << " ";
                }
                cout << '\n';
                break;
            }
        }
    }
}
