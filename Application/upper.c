//
// Created by 14477 on 2024/6/27.
//

#include "upper.h"
#include "tim.h"


Upper upper={0};
float angle = 0;
void initUpper(void)
{

}
void controlUpper(void)
{

}
void updateBlock(uint8_t *rx,Upper *upper_)
{
    upper_->block.x = rx[0];
}

