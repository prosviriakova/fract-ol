/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:53:39 by oprosvir          #+#    #+#             */
/*   Updated: 2024/05/12 00:57:29 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// TODO: refactor! NORM
void mandelbrot(t_fractol *app) {
    int x, y, iteration;
    double aspect_ratio = (double)WIN_WIDTH / WIN_HEIGHT;
    double real, imag, new_real, new_imag;
    double scale_real = 3.5 / WIN_WIDTH * app->zoom;
    double scale_imag = scale_real * aspect_ratio;

    for (y = 0; y < WIN_HEIGHT; y++) {
        for (x = 0; x < WIN_WIDTH; x++) {
            real = (x - WIN_WIDTH / 2) * scale_real + app->offset_x;
            imag = (y - WIN_HEIGHT / 2) * scale_imag + app->offset_y;
            new_real = real;
            new_imag = imag;

            iteration = 0;
            while (new_real * new_real + new_imag * new_imag < 4 && iteration < app->max_iterations) {
                double temp_real = new_real * new_real - new_imag * new_imag + real;
                new_imag = 2 * new_real * new_imag + imag;
                new_real = temp_real;
                iteration++;
            }

            int color = get_color(iteration, app->max_iterations);
            put_pixel(app, x, y, color);
        }
    }
}
