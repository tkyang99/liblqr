/* LiquidRescaling Library
 * Copyright (C) 2007 Carlo Baldassi (the "Author") <carlobaldassi@gmail.com>.
 * All Rights Reserved.
 *
 * This library implements the algorithm described in the paper
 * "Seam Carving for Content-Aware Image Resizing"
 * by Shai Avidan and Ariel Shamir
 * which can be found at http://www.faculty.idc.ac.il/arik/imret.pdf
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; version 3 dated June, 2007.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/> 
 */


#ifndef __LQR_ENERGY_PRIV_H__
#define __LQR_ENERGY_PRIV_H__

#ifndef __LQR_BASE_H__
#error "lqr_base.h must be included prior to lqr_energy_priv.h"
#endif /* __LQR_BASE_H__ */

#ifndef __LQR_GRADIENT_H__
#error "lqr_gradient.h must be included prior to lqr_energy_priv.h"
#endif /* __LQR_GRADIENT_PUB_H__ */

typedef gfloat (*LqrEnergyFuncBuiltin) (LqrCarver*, gint, gint);
typedef gfloat (*LqrReadFunc) (LqrCarver*, gint, gint);
/* typedef glfoat (*LqrReadFuncAbs) (LqrCarver*, gint, gint, gint, gint); */

struct _LqrEnergyBuiltin
{
  LqrEnergyFuncBuiltin ef;
  LqrReadFunc rf;
  LqrGradFunc gf;
  //LqrReadFuncAbs rfabs;
};

typedef struct _LqrEnergyBuiltin LqrEnergyBuiltin;


inline gfloat lqr_pixel_get_norm (void * src, gint src_ind, LqrColDepth col_depth);
inline gfloat lqr_pixel_get_rgbcol (void *rgb, gint rgb_ind, LqrColDepth col_depth, LqrImageType image_type, gint channel);
inline gfloat lqr_carver_read_brightness_std (LqrCarver * r, gint x, gint y);
inline gfloat lqr_carver_read_brightness_grey (LqrCarver * r, gint x, gint y);
gfloat lqr_carver_read_brightness_custom (LqrCarver * r, gint x, gint y);
inline gfloat lqr_carver_read_brightness (LqrCarver * r, gint x, gint y);
inline gfloat lqr_carver_read_luma_std (LqrCarver * r, gint x, gint y);
inline gfloat lqr_carver_read_luma (LqrCarver * r, gint x, gint y);
gfloat lqr_energy_builtin (LqrCarver * r, gint x, gint y);
gfloat lqr_energy_null (LqrCarver * r, gint x, gint y);

void ** lqr_energy_buffer_new_std (LqrCarver * r, gint x, gint y, gint radius, LqrEnergyReaderType read_func_type);
void ** lqr_energy_buffer_new_rgba (LqrCarver * r, gint x, gint y, gint radius, LqrEnergyReaderType read_func_type);
void ** lqr_energy_buffer_new_custom (LqrCarver * r, gint x, gint y, gint radius, LqrEnergyReaderType read_func_type);
void ** lqr_energy_buffer_new (LqrCarver * r, gint x, gint y, gint radius, LqrEnergyReaderType read_func_type);
void lqr_energy_buffer_destroy (void ** buffer, gint radius, LqrEnergyReaderType read_func_type);

gfloat lqr_energy_builtin_grad_all (gint x, gint y, gint img_width, gint img_height, void ** buffer, LqrGradFunc gf);
gfloat lqr_energy_builtin_grad_norm (gint x, gint y, gint img_width, gint img_height, void ** buffer, gpointer extra_data);
gfloat lqr_energy_builtin_grad_sumabs (gint x, gint y, gint img_width, gint img_height, void ** buffer, gpointer extra_data);
gfloat lqr_energy_builtin_grad_xabs (gint x, gint y, gint img_width, gint img_height, void ** buffer, gpointer extra_data);
gfloat lqr_energy_builtin_null (gint x, gint y, gint img_width, gint img_height, void ** buffer, gpointer extra_data);

#endif /* __LQR_ENERGY_PRIV_H__ */
