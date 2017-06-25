#include "../wolf3d.h"

//cos(0) = opposite/hypotonuse sin(0) = adjacent/hypotonuse tan(0) = opposite/adjacent

double angle_finder(double x, double y)
{
  double angle;
  /* double oh; */
  /* double  */
  angle = acos(y / HYP(x, y));
  return (angle);
}

/* double hypot(double x, double y) */
/* { */
/*   double hypotonuse; */

/*   hypotonuse = 0; */
/*   hypotonuse = sqrt((pow(x, 2) + pow(y, 2))); */
/*   return (hypotonuse); */
/* } */

float wall_height(float distance)
{
  float height;
  
  height = (200 / distance);
  return (height);
}

/* double find_wall(t_graphic *info, float ang) */
/* { */
/*   double x; */
/*   double y; */
/*   int i; */
/*   int k; */
/*   double distance; */

/*   distance = 0; */
/*   x = info->you->x_pos; */
/*   y = info->you->y_pos; */
/*   i = (int)floor(y); */
/*   k = (int)floor(x); */
/*   //  printf("%f %f, value %u\n",cos(info->you->angle) , sin(info->you->angle), info->map[i][k]); */
/*   while (info->map[i][k] != 1) */
/*     { */
/*       //      printf("hello"); */
/*       x += cos(ang); */
/*       y += sin(ang); */
/*       i = (int)floor(y); */
/*       k = (int)floor(x); */
/*       distance += 1; */
/*     } */
/*   if (x > floor(x) && y > floor(y)) */
/*     distance -= (HYP(x - floor(x), y - floor(y))); */
/*   printf("dist to  next x i thin k%f\n", ceil(x) - x); */
/*   distance *= 60; */
/*   // printf("distance %f\n", distance); */
/*   //Have player position on a 25 by 25 grid. */
/*   // Need to know the direction they are facing + the angle that they get to look at. */
  
/*   return (distance); */
/* } */

void assign_color(t_graphic *info, float dist, int x, int wall_color)
{
  int i;
  int code;
  float wall_h;

  i = WIND_H - 1;
  wall_h = wall_height(dist);
  code = 3;
  while (i >= 0)
    {
      if (i <= ((WIND_H / 2) + (wall_h / 2)) &&
	  i >= ((WIND_H / 2) - (wall_h / 2)))
	info->addr[x] = info->color[wall_color];
      else
	info->addr[x] = info->color[code];
      if (i < (WIND_H / 2))
	code = 0;
      x += WIND_W;
      i--;
    }
}

void begin(t_graphic *info)
{
  int i;
  int col;
  double dist;
  double ang;
  
  i = 0;
  col = (WIND_W - 1);
  ang = info->you->angle + DEG_30;
   while (i < WIND_W && col >= 0)
    {
      // printf("%f\n", ang *(180 / M_PI));
      info->camerax = (2 * (double)col / (double)WIND_W - 1);
      info->raydirx = cos(ang) + info->planex *info->camerax;
      info->raydiry = sin(ang) + info->planey *info->camerax;
      //dist = find_wall(info, ang);
      dist = wall_distance(info, ang);
      //printf("% f\n", dist);
      if (i > (WIND_W / 2))
	assign_color(info, dist, col, 2);
      else
	assign_color(info, dist, col, 2);
      ang -= RAD(60 / WIND_W);
       col--;
      i++;
    }  
}
/* int main() */
/* { */
/*   int i = 0; */
/*   t_graphic *test; */

/*   test = (t_graphic*)malloc(sizeof(t_graphic)); */
/*   test->you = (t_person*)malloc(sizeof(t_person)); */
/*   initialize_player(test); */
/*   makeworld(test); */
/*   test->you->angle += DEG_30; */
/*   while (i < 10) */
/*     { */
/*       find_wall(test); */
/*       test->you->angle += (DEG_30 / 5); */
/*       i++; */
/*     } */
    
/*   double x = 3.0000; */
/*   double y = 4.000; */
/*   /\* printf("%f\n", pow(x, 2)); *\/ */
/*   /\* printf("%f\n", pow(y, 2)); *\/ */
 /*   /\* printf("%f\n", HYP(x, y)); *\/ */
/*   /\* printf("%f\n", angle_finder(x, y)); *\/ */
/*   /\* printf("%f\n", DEG_30); *\/ */
/*   return (0); */
/* } */
