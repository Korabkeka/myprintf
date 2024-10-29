/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeka <kkeka@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:58:08 by kkeka             #+#    #+#             */
/*   Updated: 2024/10/28 19:15:00 by kkeka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static void handle_c(int c, int **count)
{
    putchar(c);
    (**count)++;
}

static void handle_s(char *s, int **count)
{
    int i;

    i = 0;
    while (s[i])
    {
        write(1, &s[i], 1);
        (**count)+= 1;
        i++;
    }
}

static void handle_p(char c, int **count)
{
    putchar(c);
    (*count)++;
}

static void handle_d(char c, int **count)
{
    putchar(c);
    (*count)++;
}

static void handle_i(char c, int **count)
{
    putchar(c);
    (*count)++;
}

static void handle_u(char c, int **count)
{
    putchar(c);
    (*count)++;
}

static void handle_low_x(char c, int **count)
{
    putchar(c);
    (*count)++;
}

static void handle_up_x(char c, int **count)
{
    putchar(c);
    (*count)++;
}

static void handleformat(va_list args, char formatid, int *count)
{
    if (formatid == 'c')
        handle_c(va_arg(args, int), &count);
    if (formatid == 's')
        handle_s(va_arg(args, char *), &count);
    if (formatid == 'p')
        handle_p(va_arg(args, int), &count);
    if (formatid == 'd')
        handle_d(va_arg(args, int), &count);
    if (formatid == 'i')
        handle_i(va_arg(args, int), &count);
    if (formatid == 'u')
        handle_u(va_arg(args, unsigned int), & count);
    if (formatid == 'x')
        handle_low_x(va_arg(args, int), &count);
    if (formatid == 'X')
        handle_up_x(va_arg(args, int), &count);
    if (formatid == '%')
    {
        write(1, "%", 1);
        (*count)++;
    }
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int count;

    count = 0;
    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
          format++;
          handleformat(args, *format, &count);
          format++;
        }
        else
        {
            write(1, &(*format), 1);
            format++;
            count++;
        }
    }
    va_end(args);
    return (count);
}
int main() {
    // Write C code here
    int i;
    i = ft_printf("Try %s pr%%ogrami%cz.pro\n", "test", 'c');
    printf("%i\n", i);

    return 0;
}