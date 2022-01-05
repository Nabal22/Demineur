#pragma once
#ifndef _PRODCOUP_
#define _PRODCOUP_

#include <iostream>
#include <time.h>
#include <cassert>
#include "Grille.h"

/**
 * @brief LProduit un nouveau coup
 * @param[in-out] partie : la grille actuelle
 * @param[in] colonne : le nombre de colonne
 * @param[in] ligne : le nombre de ligne
 */
void prodCoup(const Grille partie, const unsigned int colonne, const unsigned int ligne);

#endif