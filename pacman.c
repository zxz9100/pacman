#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
//색깔
#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define PINK "\033[35m"
#define CYAN "\033[36m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"

//함수
int map();
int reset();
int movement();
int Executemovement();
int ainumber1();
int ainumber2();
int ainumber3();
int ainumber4();

//변수
char fabric[220];
long location;
int input;
int InputVariables;
int score = 0;
int ai1location;
int ai2location;
int ai3location;
int ai4location;
int ai1;
int ai2;
int ai3;
int ai4;
int order = 0;
int life = 1;


void clear() {
    printf("\033[H\033[J");
}

int main()
{
    srand(time(NULL));

    reset();
    //플레이어 소환
    fabric[190] = 'o';
    //ai 소환
    fabric[108] = '@';
    fabric[109] = '*';
    fabric[110] = '#';
    fabric[111] = '$';
    do
    {
        //printf("%d\n", order);
        printf("팩맨 게임\n");
        printf("조작 : w, a, s, d\n");
        printf("점수 : %d\n", score);
        map();
        movement();
        ainumber1();
        ainumber2();
        ainumber3();
        ainumber4();
        usleep(100000); 
        clear();
        if (order < 121)
        {
            ++order;
        }
    } while (score < 99 && life == 1);
    if (life == 0)
    {
        printf("게임 오버");
    }
    else if (life == 1)
    {
        printf("승리!!!");
    }
    
    return 0;
}

int map() {
    for (int i = 0; i < 220; i += 20) {
        for (int j = 0; j < 20; j++) {
            char ch = fabric[i + j];
            switch (ch) {
                case '=': printf(BLUE "%c " RESET, ch); break;
                case 'o': printf(YELLOW "%c " RESET, ch); break;
                case '*': printf(RED "%c " RESET, ch); break;
                case '#': printf(GREEN  "%c " RESET, ch); break;
                case '$': printf(CYAN "%c " RESET, ch); break;
                case '@': printf(PINK "%c " RESET, ch); break;
                default: printf("%c ", ch); break;
            }
        }
        printf("\n");
    }
    return 0;
}
int ainumber1()
{
    while (order > 30)
    {
        for (ai1location = 0; ai1location < 220; ai1location++)
        {
            if (fabric[ai1location] == '*')
            {
                break;
            }
        }
        int random = rand() % 4;

        if (random == 0)
        {
            ai1 = ai1location - 20;
        }
        else if (random == 1)
        {
            ai1 = ai1location - 1;
        }
        else if (random == 2)
        {
            ai1 = ai1location + 20;
        }
        else if (random == 3)
        {
            ai1 = ai1location + 1;
        }

        if (fabric[ai1] == '=' || fabric[ai1] == '@' || fabric[ai1] == '#' || fabric[ai1] == '$' || ai1 < 0 || ai1 > 219)
        {
            break;
        }
        if (fabric[ai1] == '.')
        {
           fabric[ai1location] = '.';  
        }
        else if (fabric[ai1] = ' ')
        {
           fabric[ai1location] = ' ';    
        }
        else if (fabric[ai1] == 'o')
        {
            life = 0;
        }

        fabric[ai1] = '*';
        break;
    }

    return 0;
}

int ainumber2()
{
    while (order > 60)
    {
        for (ai2location = 0; ai2location < 220; ai2location++)
        {
            if (fabric[ai2location] == '#')
            {
                break;
            }
        }
        int random = rand() % 4;

        if (random == 0)
        {
            ai2 = ai2location - 20;
        }
        else if (random == 1)
        {
            ai2 = ai2location - 1;
        }
        else if (random == 2)
        {
            ai2 = ai2location + 20;
        }
        else if (random == 3)
        {
            ai2 = ai2location + 1;
        }

        if (fabric[ai2] == '=' || fabric[ai2] == '@' || fabric[ai2] == '*' || fabric[ai2] == '$' || ai2 < 0 || ai2 > 219)
        {
            break;
        }
        if (fabric[ai2] == '.')
        {
           fabric[ai2location] = '.';  
        }
        else if (fabric[ai2] == ' ')
        {
           fabric[ai2location] = ' ';    
        }
        else if (fabric[ai2] == 'o')
        {
            life = 0;
        }
        
        fabric[ai2] = '#';
        break;
    }

    return 0;
}

int ainumber3()
{
    while (order > 90)
    {
        for (ai3location = 0; ai3location < 220; ai3location++)
        {
            if (fabric[ai3location] == '@')
            {
                break;
            }
        }
        int random = rand() % 4;

        if (random == 0)
        {
            ai3 = ai3location - 20;
        }
        else if (random == 1)
        {
            ai3 = ai3location - 1;
        }
        else if (random == 2)
        {
            ai3 = ai3location + 20;
        }
        else if (random == 3)
        {
            ai3 = ai3location + 1;
        }

        if (fabric[ai3] == '=' || fabric[ai3] == '*' || fabric[ai3] == '#' || fabric[ai3] == '$' || ai3 < 0 || ai3 > 219)
        {
            break;
        }
        if (fabric[ai3] == '.')
        {
           fabric[ai3location] = '.';  
        }
        else if (fabric[ai3] = ' ')
        {
           fabric[ai3location] = ' ';    
        }
        else if (fabric[ai3] == 'o')
        {
            life = 0;
        }

        fabric[ai3] = '@';
        break;
    }

    return 0;
}

int ainumber4()
{
    while (order > 120)
    {
        for (ai4location = 0; ai4location < 220; ai4location++)
        {
            if (fabric[ai4location] == '$')
            {
                break;
            }
        }
        int random = rand() % 4;

        if (random == 0)
        {
            ai4 = ai4location - 20;
        }
        else if (random == 1)
        {
            ai4 = ai4location - 1;
        }
        else if (random == 2)
        {
            ai4 = ai4location + 20;
        }
        else if (random == 3)
        {
            ai4 = ai4location + 1;
        }

        if (fabric[ai4] == '=' || fabric[ai4] == '@' || fabric[ai4] == '*' || fabric[ai4] == '#' || ai4 < 0 || ai4 > 219)
        {
            break;
        }
        if (fabric[ai4] == '.')
        {
           fabric[ai4location] = '.';  
        }
        else if(fabric[ai4] == ' ')
        {
           fabric[ai4location] = ' ';    
        }
        else if (fabric[ai4] == 'o')
        {
            life = 0;
        }
        
        fabric[ai4] = '$';
        break;
    }

    return 0;
}

int Executemovement()
{
    while (input == 1)
    {
        for (location = 0; location < 220; location++)
        {
            if (fabric[location] == 'o')
            {
                InputVariables = location - 20;
                break;
            }
        }
        if (fabric[InputVariables] == '=' || location < 0)
        {
            break;
        }
        fabric[location] = ' ';
        if (fabric[InputVariables] == '.')
        {
            ++score;
        }
        else if (fabric[InputVariables] == '*' || fabric[InputVariables] == '#' || fabric[InputVariables] == '$' || fabric[InputVariables] == '@')
        {
            life = 0;
        }
        fabric[InputVariables] = 'o';
        break;
    }

    while (input == 2)
    {
        for (location = 0; location < 220; location++)
        {
            if (fabric[location] == 'o')
            {
                InputVariables = location - 1;
                break;
            }
        }
        if (fabric[InputVariables] == '=')
        {
            break;
        }
        fabric[location] = ' ';
        if (fabric[InputVariables] == '.')
        {
            ++score;
        }
        else if (fabric[InputVariables] == '*' || fabric[InputVariables] == '#' || fabric[InputVariables] == '$' || fabric[InputVariables] == '@')
        {
            life = 0;
        }
        fabric[InputVariables] = 'o';
        break;
    }

    while (input == 3)
    {
        for (location = 0; location < 220; location++)
        {
            if (fabric[location] == 'o')
            {
                InputVariables = location + 20;
                break;
            }
        }
        if (fabric[InputVariables] == '=' || location > 219)
        {
            break;
        }
        fabric[location] = ' ';
        if (fabric[InputVariables] == '.')
        {
            ++score;
        }
        else if (fabric[InputVariables] == '*' || fabric[InputVariables] == '#' || fabric[InputVariables] == '$' || fabric[InputVariables] == '@')
        {
            life = 0;
        }
        fabric[InputVariables] = 'o';
        break;
    }

    while (input == 4)
    {
        for (location = 0; location < 220; location++)
        {
            if (fabric[location] == 'o')
            {
                InputVariables = location + 1;
                break;
            }
        }
        if (fabric[InputVariables] == '=')
        {
            break;
        }
        fabric[location] = ' ';
        if (fabric[InputVariables] == '.')
        {
            ++score;
        }
        else if (fabric[InputVariables] == '*' || fabric[InputVariables] == '#' || fabric[InputVariables] == '$' || fabric[InputVariables] == '@')
        {
            life = 0;
        }
        fabric[InputVariables] = 'o';
        break;
    }

    return 0;
}

int movement() 
{
    if (_kbhit())
    {
        char ch = _getch();
        if (ch == 'w') 
        {
            input = 1;
        } 
        else if (ch == 'a') 
        {
            input = 2;
        }
        else if (ch == 's')
        {
            input = 3;
        }
        else if (ch == 'd')
        {
            input = 4;
        }
    }
    Executemovement();

    return 0;
}

int reset()
{
    //윗쪽 벽
    fabric[0] = '=';fabric[1] = '=';fabric[2] = '=';fabric[3] = '=';fabric[4] = '=';fabric[5] = '=';fabric[6] = '=';fabric[7] = '=';fabric[8] = '=';fabric[9] = '=';fabric[10] = '=';fabric[11] = '=';fabric[12] = '=';fabric[13] = '=';fabric[14] = '=';fabric[15] = '=';fabric[16] = '=';fabric[17] = '=';fabric[18] = '=';fabric[19] = '=';
    //1번째 줄
    fabric[20] = '=';fabric[21] = '.';fabric[22] = '.';fabric[23] = '.';fabric[24] = '.';fabric[25] = '=';fabric[26] = '.';fabric[27] = '.';fabric[28] = '.';fabric[29] = '.';fabric[30] = '.';fabric[31] = '.';fabric[32] = '.';fabric[33] = '.';fabric[34] = '=';fabric[35] = '.';fabric[36] = '.';fabric[37] = '.';fabric[38] = '.';fabric[39] = '=';
    //2번째 줄
    fabric[40] = '=';fabric[41] = '.';fabric[42] = '=';fabric[43] = '=';fabric[44] = '.';fabric[45] = '=';fabric[46] = '.';fabric[47] = '=';fabric[48] = '=';fabric[49] = '=';fabric[50] = '=';fabric[51] = '=';fabric[52] = '=';fabric[53] = '.';fabric[54] = '=';fabric[55] = '.';fabric[56] = '=';fabric[57] = '=';fabric[58] = '.';fabric[59] = '=';
    //3번째줄
    fabric[60] = '=';fabric[61] = '.';fabric[62] = '=';fabric[63] = '.';fabric[64] = '.';fabric[65] = '.';fabric[66] = '.';fabric[67] = '.';fabric[68] = '.';fabric[69] = '.';fabric[70] = '.';fabric[71] = '.';fabric[72] = '.';fabric[73] = '.';fabric[74] = '.';fabric[75] = '.';fabric[76] = '.';fabric[77] = '=';fabric[78] = '.';fabric[79] = '=';
    //4번째줄
    fabric[80] = '=';fabric[81] = '.';fabric[82] = '=';fabric[83] = '.';fabric[84] = '=';fabric[85] = '=';fabric[86] = '.';fabric[87] = '=';fabric[88] = '=';fabric[89] = ' ';fabric[90] = ' ';fabric[91] = '=';fabric[92] = '=';fabric[93] = '.';fabric[94] = '=';fabric[95] = '=';fabric[96] = '.';fabric[97] = '=';fabric[98] = '.';fabric[99] = '=';
    //5번째줄
    fabric[100] = '=';fabric[101] = '.';fabric[102] = '.';fabric[103] = '.';fabric[104] = '.';fabric[105] = '.';fabric[106] = '.';fabric[107] = '=';fabric[108] = ' ';fabric[109] = ' ';fabric[110] = ' ';fabric[111] = ' ';fabric[112] = '=';fabric[113] = '.';fabric[114] = '.';fabric[115] = '.';fabric[116] = '.';fabric[117] = '.';fabric[118] = '.';fabric[119] = '=';
    //6번째줄
    fabric[120] = '=';fabric[121] = '.';fabric[122] = '=';fabric[123] = '.';fabric[124] = '=';fabric[125] = '=';fabric[126] = '.';fabric[127] = '=';fabric[128] = '=';fabric[129] = '=';fabric[130] = '=';fabric[131] = '=';fabric[132] = '=';fabric[133] = '.';fabric[134] = '=';fabric[135] = '=';fabric[136] = '.';fabric[137] = '=';fabric[138] = '.';fabric[139] = '=';
    //7번째줄
    fabric[140] = '=';fabric[141] = '.';fabric[142] = '=';fabric[143] = '.';fabric[144] = '.';fabric[145] = '.';fabric[146] = '.';fabric[147] = '.';fabric[148] = '.';fabric[149] = '.';fabric[150] = '.';fabric[151] = '.';fabric[152] = '.';fabric[153] = '.';fabric[154] = '.';fabric[155] = '.';fabric[156] = '.';fabric[157] = '=';fabric[158] = '.';fabric[159] = '=';
    //8번째줄
    fabric[160] = '=';fabric[161] = '.';fabric[162] = '=';fabric[163] = '=';fabric[164] = '.';fabric[165] = '=';fabric[166] = '.';fabric[167] = '=';fabric[168] = '=';fabric[169] = '=';fabric[170] = '=';fabric[171] = '=';fabric[172] = '=';fabric[173] = '.';fabric[174] = '=';fabric[175] = '.';fabric[176] = '=';fabric[177] = '=';fabric[178] = '.';fabric[179] = '=';
    //9번째줄
    fabric[180] = '=';fabric[181] = '.';fabric[182] = '.';fabric[183] = '.';fabric[184] = '.';fabric[185] = '=';fabric[186] = '.';fabric[187] = '.';fabric[188] = '.';fabric[189] = '.';fabric[190] = '.';fabric[191] = '.';fabric[192] = '.';fabric[193] = '.';fabric[194] = '=';fabric[195] = '.';fabric[196] = '.';fabric[197] = '.';fabric[198] = '.';fabric[199] = '=';
    //아렛쪽 벽
    fabric[200] = '=';fabric[201] = '=';fabric[202] = '=';fabric[203] = '=';fabric[204] = '=';fabric[205] = '=';fabric[206] = '=';fabric[207] = '=';fabric[208] = '=';fabric[209] = '=';fabric[210] = '=';fabric[211] = '=';fabric[212] = '=';fabric[213] = '=';fabric[214] = '=';fabric[215] = '=';fabric[216] = '=';fabric[217] = '=';fabric[218] = '=';fabric[219] = '=';

    return 0;
}
