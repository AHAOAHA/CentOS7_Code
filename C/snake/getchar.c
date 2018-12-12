/*************************************************************************
*File Name: getchar.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Mon Dec 10 15:49:56 2018
 ************************************************************************/
/*
 * 不输入回车即读取字符
 */

#include"snake.h"
static struct termios oldt;

//restore terminal settings
void restore_terminal_settings(void)
{
    //Apply saved settings
    tcsetattr(0, TCSANOW, &oldt); 
}

//make terminal read 1 char at a time
void disable_terminal_return(void)
{
    struct termios newt;
    
    //save terminal settings
    tcgetattr(0, &oldt); 
    //init new settings
    newt = oldt;  
    //change settings
    newt.c_lflag &= ~(ICANON | ECHO);
    //apply settings
    tcsetattr(0, TCSANOW, &newt);
    
    //make sure settings will be restored when program ends
    atexit(restore_terminal_settings);
}

