/*******************************************************************************
 *
 * Copyright (C) 2012 Jorge Aparicio <jorge.aparicio.r@gmail.com>
 *
 * This file is part of bareCortexM.
 *
 * bareCortexM is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * bareCortexM is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with bareCortexM. If not, see <http://www.gnu.org/licenses/>.
 *
 ******************************************************************************/

#include <stdint.h>

#define INLINE inline __attribute__((always_inline))
typedef uint32_t u32;

int main();
extern u32 __etext;
extern u32 __data_start__;
extern u32 __data_end__;
extern u32 __bss_start__;
extern u32 __bss_end__;

/**
 * @brief Loads initialized data to RAM, and clears uninitialized data.
 */
static INLINE void initializeData()
{
  u32 *pSrc;
  u32 *pDest;

  // Load initialized data from FLASH to RAM
  pSrc = &__etext;
  pDest = &__data_start__;

  while (pDest < &__data_end__) {
    *pDest++ = *pSrc++;
  }

  // Clear uninitialized data
  pDest = &__bss_start__;

  while (pDest < &__bss_end__) {
    *pDest++ = 0;
  }
}

void resetHandler()
{
  initializeData();

  main();
}
