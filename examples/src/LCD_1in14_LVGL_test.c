/*****************************************************************************
* | File      	:   LCD_1in14_LVGL_test.c
* | Author      :   Waveshare team
* | Function    :   1.14inch LCD LVGL demo
* | Info        :
*----------------
* |	This version:   V1.0
* | Date        :   2025-01-07
* | Info        :
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
#include "LCD_Test.h"
#include "LCD_1in14.h"

static void Widgets_Init(lvgl_data_struct *dat);
static void LCD_1IN14_KEY_Init(void);
static uint16_t LCD_1IN14_Read_KEY(void);

/********************************************************************************
function:   Main function
parameter:
********************************************************************************/
int LCD_1in14_test(void)
{
    if(DEV_Module_Init()!=0){
        return -1;
    }

    /* LCD Init */
    printf("1.14inch LCD LVGL demo...\r\n");
    LCD_1IN14_Init(HORIZONTAL);

    DEV_SET_PWM(25);
    LCD_1IN14_Clear(BLACK);

    /*Config parameters*/
    LCD_SetWindows = LCD_1IN14_SetWindows;
    DISP_HOR_RES = LCD_1IN14_HEIGHT;
    DISP_VER_RES = LCD_1IN14_WIDTH;

    /*Init LVGL data structure*/    
    lvgl_data_struct *dat = (lvgl_data_struct *)malloc(sizeof(lvgl_data_struct));
    memset(dat->scr, 0, sizeof(dat->scr));
    dat->click_num = 0;
    
    /*Init LVGL*/
    LVGL_Init();
    Widgets_Init(dat);



//    while(1)
//    {
//        lv_task_handler();
//        DEV_Delay_ms(5); 
//    }
//    
//    DEV_Module_Exit();
    return 0;
}


lv_obj_t * label1, * label2;


void Show_Params(uint8_t uart, uint32_t baud, uint8_t data_bits, char parity, uint8_t stops_bits)
{
  lv_obj_t * label = uart == 0 ? label1 : label2;

  if (baud)
  {
    lv_label_set_text_fmt(label, "%d %d%c%d", baud, data_bits, parity, stops_bits);
  }
  else
  {
//    lv_label_set_text(label, LV_SYMBOL_CLOSE " OFF " LV_SYMBOL_CLOSE);
    lv_label_set_text(label, LV_SYMBOL_CLOSE);
  }
}

/********************************************************************************
function:   Initialize Widgets
parameter:
********************************************************************************/
static void Widgets_Init(lvgl_data_struct *dat)
{
    static lv_style_t style_label;
    lv_style_init(&style_label);
    lv_style_set_text_font(&style_label, &lv_font_montserrat_36);

    lv_style_set_bg_color(&style_label, lv_color_black());
    lv_style_set_text_color(&style_label, lv_color_white());

    /*Screen1: Just a picture*/
    dat->scr[0] = lv_obj_create(NULL);
    
    /*Declare and load the image resource*/
//    LV_IMG_DECLARE(LCD_1inch14);
//    lv_obj_t *img1 = lv_img_create(dat->scr[0]);
//    lv_img_set_src(img1, &LCD_1inch14);

    /*Align the image to the center of the screen*/
//    lv_obj_align(img1, LV_ALIGN_CENTER, 0, 0);


    lv_obj_add_style(dat->scr[0], &style_label, 0);


    label1 = lv_label_create(dat->scr[0]);
    lv_label_set_long_mode(label1, LV_LABEL_LONG_CLIP);
    lv_obj_set_style_text_align(label1, LV_TEXT_ALIGN_RIGHT, 0);
    //lv_label_set_recolor(label1, true);

    lv_obj_set_pos(label1, 5, 15);     // 240x135
    lv_obj_set_size(label1, 215, 60);


    label2 = lv_label_create(dat->scr[0]);
    lv_label_set_long_mode(label2, LV_LABEL_LONG_CLIP);
    lv_obj_set_style_text_align(label2, LV_TEXT_ALIGN_RIGHT, 0);
    //lv_label_set_recolor(label2, true);

    lv_obj_set_pos(label2, 5, 75);
    lv_obj_set_size(label2, 215, 60);


    /*Load the first screen as the current active screen*/
    lv_scr_load(dat->scr[0]);
}
