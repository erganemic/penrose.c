void wb(char p[], float z[], float i, float j, float k, float sA, float cA, float sB, float cB, float x1, float y1, float x2, float y2, float xtr, float ytr, char rc)
{
                    float xt = x1 * i + x2 * j + xtr;
                    float yt = y1 * i + y2 * j + ytr;

                    float xr = -1 * sB * sA * xt + sB * cA * yt + cB * k;
                    float yr = cA * xt + sA * yt;
                    float zr = cB * sA * xt + -1 * cB * cA * yt + sB * k;
                    float D = 1 / (zr + 25);

                    int x = (160/2) + 2 * 55 * D * xr;
                    int y = (44/2) - 55 * D * yr;

                    if (0 < x && x < 160 && 0 < y && y < 44) {

                        int bp = (160 * y) + x;
                        if (D >= z[bp]) {
                            z[bp] = D;

                            p[bp] = rc;
                        }
                    }
}

void main() {
    float z[7040];
    char p[7040];

    printf("\x1b[2J");

    for (float A = 0, B = 0;; A += 0.04, B += 0.03) {
        memset(p, 32, 7040);
        memset(z, 0, sizeof(float) * 7040);
       
        float sA = sin(A), cA = cos(A);
        float sB = sin(B), cB = cos(B);
       
        for (float k = 0; k < 1.5; k += 0.07) {
            for (float i = 0; i <1; i += 0.02) {
                for (float j = 0; j < 1; j += 0.02) {
                    wb(p, z, i, j, k, sA, cA, cB, sB, 4.3, 7.74, -0.6, 1.08, -4, -1.9, '@');
                    wb(p, z, i, j, k, sA, cA, cB, sB,  3.3, -5.94, 0.5, .9, -1, 6, '@');
                    wb(p, z, i, j, k, sA, cA, cB, sB, 4.3, -7.74, 1, 0, 0, 7, '+');
                    wb(p, z, i, j, k, sA, cA, cB, sB, 6, 0, 0.45, 0.81, -2, -0.5, '+');
                    wb(p, z, i, j, k, sA, cA, cB, sB, 3.1, 5.58, -0.5, .9, -3.2, -2.0, '&');
                    wb(p, z, i, j, k, sA, cA, cB, sB, 8.8, 0, 0.55, 0.99, -3.9, -1.9, '&');
                }
            }
        }
       
        printf("\x1b[H");

        for (int bp = 0; bp < 7041; bp++) {

            if (bp % 160 == 0)
                putchar('\n');
            else
                putchar(p[bp]);
        }
    }
}
