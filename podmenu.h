int podmenu(char *fmt, ...)
{
	va_list ap;
                   int d;
                   char c, *p, *s;

	va_start(ap, fmt);
                   while (*fmt)
                        switch(*fmt++) {
                        case 's':           /* napis */
                             s = va_arg(ap, char *);
                             printf("string %s\n", s);
                             break;
                        case 'd':           /* int */
                             d = va_arg(ap, int);
                             printf("int %d\n", d);
                             break;
                        case 'c':           /* char */
                                      /* wystêpuje tu potrzeba rzutowania, gdy¿ va_arg
                                         pobiera w pe³ni awansowane typy */
                             c = (char) va_arg(ap, int);
                             printf("char %c\n", c);
                             break;
                        }
	va_end(ap);
}



