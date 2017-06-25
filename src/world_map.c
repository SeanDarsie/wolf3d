#include "../wolf3d.h"

//void make_block(t_world *piece, int x, int y, int z)
//{
//  t_world *tmp;
//
//  tmp = (t_world*)malloc(sizeof(t_world));
//  tmp->next = NULL;
//  tmp->z = z;
//  tmp->x = x;
//  tmp->y = y;
//  piece->next = tmp;
//}
//
//void worldmaker(t_world *world)
//{
//  int x;
//  int y;
//
//  y = 0;
//  while (y < IMG_H)
//    {
//      x = 0;
//      while (x <= IMG_W)
//	{
//	  if (y == 0 || x == 0 || x == 10 || y == 10)
//	    make_block(world, x, y, 1);
//	  else if (y % 3 == 0 && x % 3 == 0)
//	    make_block(world, x, y, 1);
//	  else
//	    make_block(world, x, y, 0);
//	  world = world->next;
//	  x++;
//	}
//      y++;
//    }
//}


void makeworld(t_graphic *info)
{
  uint32_t y;
  uint32_t x;

  y = 0;
  while (y <= IMG_H)
    {
      x = 0;
      while (x <= IMG_W)
	{
	  if (y == 0 || y == IMG_H || x == 0 || x == IMG_W)
	    info->map[y][x] = 1;
	  /* else if (y % 3 == 0 && x % 3 == 0) */
	  /*   info->map[y][x] = 1; */
	  else
	    info->map[y][x] = 0;
	  x++;
	}
      y++;
    } 
}

/* int main() */
/* { */
/*   float x, y; */
/*   int i,k; */
/*   t_graphic *test; */
  

/*   x = 0; */
/*   y = 0; */
/*   i = 0; */
/*   k = 0; */
/*   test = (t_graphic*)malloc(sizeof(t_graphic)); */
/*   makeworld(test); */
/*   while (test->map[i][k] && y <= 25) */
/*     { */
/*       x = 0; */
/*       while (x <= 25) */
/* 	{ */
/* 	  //  printf("%f\t%f", x, y); */
/* 	  i = (int)/\* floor(y) *\/y; */
/* 	  k = (int)/\* floor(x) *\/x; */
/* 	  //printf("\t%i\t%i\n", k, i); */

/* 	  // if (test->map[i][k] == 1) */
/* 	    printf("%u", test->map[i][k]); */
/* 	  x += 0.3; */
/* 	} */
/*       printf("\n"); */
/*       y += 0.3; */
/*     } */
/*   free(test); */

  
/* } */
