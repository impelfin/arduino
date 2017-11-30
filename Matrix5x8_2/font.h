/*
 * 목  적 : 5x8 LED DOT MATRIX에 출력할 폰트 정보
 * 작성일 : 2014년 2월 3일
 * 작성자 : 최의신
 *
 */

/*
 * 5x8 matrix LED의 폰트
 */
char METRIX_FONT [][5]  = {
                            {0x7F, 0x88, 0x88, 0x88, 0x7F}, /*  0 - A         */
                            {0xFF, 0x91, 0x91, 0x91, 0x6E}, /*  1 - B         */
                            {0x7E, 0x81, 0x81, 0x81, 0x42}, /*  2 - C         */
                            {0xFF, 0x81, 0x81, 0x42, 0x3C}, /*  3 - D         */
                            {0xFF, 0x91, 0x91, 0x91, 0x81}, /*  4 - E         */
                            {0xFF, 0x90, 0x90, 0x90, 0x80}, /*  5 - F         */
                            {0x7E, 0x81, 0x89, 0x89, 0x4E}, /*  6 - G         */
                            {0xFF, 0x10, 0x10, 0x10, 0xFF}, /*  7 - H         */
                            {0x81, 0x81, 0xFF, 0x81, 0x81}, /*  8 - I         */
                            {0x06, 0x01, 0x01, 0x01, 0xFE}, /*  9 - J         */
                            {0xFF, 0x18, 0x24, 0x42, 0x81}, /* 10 - K         */
                            {0xFF, 0x01, 0x01, 0x01, 0x01}, /* 11 - L         */
                            {0xFF, 0x40, 0x30, 0x40, 0xFF}, /* 12 - M         */
                            {0xFF, 0x40, 0x30, 0x08, 0xFF}, /* 13 - N         */
                            {0x7E, 0x81, 0x81, 0x81, 0x7E}, /* 14 - O         */
                            {0xFF, 0x88, 0x88, 0x88, 0x70}, /* 15 - P         */
                            {0x7E, 0x81, 0x85, 0x82, 0x7D}, /* 16 - Q         */
                            {0xFF, 0x88, 0x8C, 0x8A, 0x71}, /* 17 - R         */
                            {0x61, 0x91, 0x91, 0x91, 0x8E}, /* 18 - S         */
                            {0x80, 0x80, 0xFF, 0x80, 0x80}, /* 19 - T         */
                            {0xFE, 0x01, 0x01, 0x01, 0xFE}, /* 20 - U         */
                            {0xF0, 0x0C, 0x03, 0x0C, 0xF0}, /* 21 - V         */
                            {0xFF, 0x02, 0x0C, 0x02, 0xFF}, /* 22 - W         */
                            {0xC3, 0x24, 0x18, 0x24, 0xC3}, /* 23 - X         */
                            {0xE0, 0x10, 0x0F, 0x10, 0xE0}, /* 24 - Y         */
                            {0x83, 0x85, 0x99, 0xA1, 0xC1}, /* 25 - Z         */
                            {0x06, 0x29, 0x29, 0x29, 0x1F}, /* 26 - a         */
                            {0xFF, 0x09, 0x11, 0x11, 0x0E}, /* 27 - b         */
                            {0x1E, 0x21, 0x21, 0x21, 0x12}, /* 28 - c         */
                            {0x0E, 0x11, 0x11, 0x09, 0xFF}, /* 29 - d         */
                            {0x0E, 0x15, 0x15, 0x15, 0x0C}, /* 30 - e         */
                            {0x08, 0x7F, 0x88, 0x80, 0x40}, /* 31 - f         */
                            {0x30, 0x49, 0x49, 0x49, 0x7E}, /* 32 - g         */
                            {0xFF, 0x08, 0x10, 0x10, 0x0F}, /* 33 - h         */
                            {0x00, 0x00, 0x5F, 0x00, 0x00}, /* 34 - i         */
                            {0x02, 0x01, 0x21, 0xBE, 0x00}, /* 35 - j         */
                            {0xFF, 0x04, 0x0A, 0x11, 0x00}, /* 36 - k         */
                            {0x00, 0x81, 0xFF, 0x01, 0x00}, /* 37 - l         */
                            {0x3F, 0x20, 0x18, 0x20, 0x1F}, /* 38 - m         */
                            {0x3F, 0x10, 0x20, 0x20, 0x1F}, /* 39 - n         */
                            {0x0E, 0x11, 0x11, 0x11, 0x0E}, /* 40 - o         */
                            {0x3F, 0x24, 0x24, 0x24, 0x18}, /* 41 - p         */
                            {0x10, 0x28, 0x28, 0x18, 0x3F}, /* 42 - q         */
                            {0x1F, 0x08, 0x10, 0x10, 0x08}, /* 43 - r         */
                            {0x09, 0x15, 0x15, 0x15, 0x02}, /* 44 - s         */
                            {0x20, 0xFE, 0x21, 0x01, 0x02}, /* 45 - t         */
                            {0x1E, 0x01, 0x01, 0x02, 0x1F}, /* 46 - u         */
                            {0x1C, 0x02, 0x01, 0x02, 0x1C}, /* 47 - v         */
                            {0x1E, 0x01, 0x0E, 0x01, 0x1E}, /* 48 - w         */
                            {0x11, 0x0A, 0x04, 0x0A, 0x11}, /* 49 - x         */
                            {0x00, 0x39, 0x05, 0x05, 0x3E}, /* 50 - y         */
                            {0x11, 0x13, 0x15, 0x19, 0x11}, /* 51 - z         */
                            {0x00, 0x41, 0xFF, 0x01, 0x00}, /* 52 - 1         */
                            {0x43, 0x85, 0x89, 0x91, 0x61}, /* 53 - 2         */
                            {0x42, 0x81, 0x91, 0x91, 0x6E}, /* 54 - 3         */
                            {0x18, 0x28, 0x48, 0xFF, 0x08}, /* 55 - 4         */
                            {0xF2, 0x91, 0x91, 0x91, 0x8E}, /* 56 - 5         */
                            {0x1E, 0x29, 0x49, 0x89, 0x86}, /* 57 - 6         */
                            {0x80, 0x8F, 0x90, 0xA0, 0xC0}, /* 58 - 7         */
                            {0x6E, 0x91, 0x91, 0x91, 0x6E}, /* 59 - 8         */
                            {0x70, 0x89, 0x89, 0x8A, 0x7C}, /* 60 - 9         */
                            {0x60, 0x80, 0x8D, 0x90, 0x60}, /* 61 - ?         */
                            {0x00, 0x00, 0xFD, 0x00, 0x00}, /* 62 - !         */
                            {0x7E, 0x89, 0x91, 0xA1, 0x7E}, /* 63 - 0         */
                            {0x66, 0x89, 0x8F, 0x81, 0x7E}, /* 64 - @         */
                            {0x24, 0xFF, 0x24, 0xFF, 0x24}, /* 65 - #         */
                            {0x76, 0x89, 0x95, 0x62, 0x05}, /* 66 - &         */
                            {0x00, 0x3C, 0x42, 0x81, 0x00}, /* 67 - (         */
                            {0x00, 0x81, 0x42, 0x3C, 0x00}, /* 68 - )         */
                            {0x08, 0x08, 0x3E, 0x08, 0x08}, /* 69 - "+"       */
                            {0x08, 0x08, 0x08, 0x08, 0x08}, /* 70 - -         */
                            {0x14, 0x14, 0x14, 0x14, 0x14}, /* 71 - =         */
                            {0x10, 0x10, 0x54, 0x38, 0x10}, /* 72 - R arrow   */
                            {0x08, 0x1C, 0x2A, 0x08, 0x08}, /* 73 - L arrow   */
                            {0x12, 0x2A, 0x7F, 0x2A, 0x24}, /* 74 - $         */
                            {0x44, 0x02, 0x12, 0x02, 0x44}, /* 75 - smile     */
                            {0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, /* 76 - 5x8 block */
                            {0x00, 0x00, 0x00, 0x00, 0x00}, /* 77 - 5x8 off block */
};

/*
 * ASCII 코드를 5x8 metrix LED 폰트로 맵핑
 */
int FONT_INDEX[] = {
                         77 /* ASCII(DEC) 0 */
                        ,77 /* ASCII(DEC) 1 */
                        ,77 /* ASCII(DEC) 2 */
                        ,77 /* ASCII(DEC) 3 */
                        ,77 /* ASCII(DEC) 4 */
                        ,77 /* ASCII(DEC) 5 */
                        ,77 /* ASCII(DEC) 6 */
                        ,77 /* ASCII(DEC) 7 */
                        ,77 /* ASCII(DEC) 8 */
                        ,77 /* ASCII(DEC) 9 */
                        ,77 /* ASCII(DEC) 10 */
                        ,77 /* ASCII(DEC) 11 */
                        ,77 /* ASCII(DEC) 12 */
                        ,77 /* ASCII(DEC) 13 */
                        ,77 /* ASCII(DEC) 14 */
                        ,77 /* ASCII(DEC) 15 */
                        ,77 /* ASCII(DEC) 16 */
                        ,77 /* ASCII(DEC) 17 */
                        ,77 /* ASCII(DEC) 18 */
                        ,77 /* ASCII(DEC) 19 */
                        ,77 /* ASCII(DEC) 20 */
                        ,77 /* ASCII(DEC) 21 */
                        ,77 /* ASCII(DEC) 22 */
                        ,77 /* ASCII(DEC) 23 */
                        ,77 /* ASCII(DEC) 24 */
                        ,77 /* ASCII(DEC) 25 */
                        ,77 /* ASCII(DEC) 26 */
                        ,77 /* ASCII(DEC) 27 */
                        ,77 /* ASCII(DEC) 28 */
                        ,77 /* ASCII(DEC) 29 */
                        ,77 /* ASCII(DEC) 30 */
                        ,77 /* ASCII(DEC) 31 */
                        ,77 /* ASCII(DEC) 32 */
                        ,62 /* ASCII ! */
                        ,75 /* ASCII " */
                        ,65 /* ASCII # */
                        ,74 /* ASCII $ */
                        ,75 /* ASCII % */
                        ,66 /* ASCII & */
                        ,75 /* ASCII ' */
                        ,67 /* ASCII ( */
                        ,68 /* ASCII ) */
                        ,75 /* ASCII * */
                        ,69 /* ASCII + */
                        ,75 /* ASCII , */
                        ,70 /* ASCII - */
                        ,75 /* ASCII . */
                        ,75 /* ASCII / */
                        ,63 /* ASCII 0 */
                        ,52 /* ASCII 1 */
                        ,53 /* ASCII 2 */
                        ,54 /* ASCII 3 */
                        ,55 /* ASCII 4 */
                        ,56 /* ASCII 5 */
                        ,57 /* ASCII 6 */
                        ,58 /* ASCII 7 */
                        ,59 /* ASCII 8 */
                        ,60 /* ASCII 9 */
                        ,75 /* ASCII : */
                        ,75 /* ASCII ; */
                        ,73 /* ASCII < */
                        ,71 /* ASCII = */
                        ,72 /* ASCII > */
                        ,75 /* ASCII ? */
                        ,75 /* ASCII @ */
                        , 0 /* ASCII A */
                        , 1 /* ASCII B */
                        , 2 /* ASCII C */
                        , 3 /* ASCII D */
                        , 4 /* ASCII E */
                        , 5 /* ASCII F */
                        , 6 /* ASCII G */
                        , 7 /* ASCII H */
                        , 8 /* ASCII I */
                        , 9 /* ASCII J */
                        ,10 /* ASCII K */
                        ,11 /* ASCII L */
                        ,12 /* ASCII M */
                        ,13 /* ASCII N */
                        ,14 /* ASCII O */
                        ,15 /* ASCII P */
                        ,16 /* ASCII Q */
                        ,17 /* ASCII R */
                        ,18 /* ASCII S */
                        ,19 /* ASCII T */
                        ,20 /* ASCII U */
                        ,21 /* ASCII V */
                        ,22 /* ASCII W */
                        ,23 /* ASCII X */
                        ,24 /* ASCII Y */
                        ,25 /* ASCII Z */
                        ,75 /* ASCII [ */
                        ,75 /* ASCII \ */
                        ,75 /* ASCII ] */
                        ,75 /* ASCII ^ */
                        ,75 /* ASCII _ */
                        ,75 /* ASCII ` */
                        ,26 /* ASCII a */
                        ,27 /* ASCII b */
                        ,28 /* ASCII c */
                        ,29 /* ASCII d */
                        ,30 /* ASCII e */
                        ,31 /* ASCII f */
                        ,32 /* ASCII g */
                        ,33 /* ASCII h */
                        ,34 /* ASCII i */
                        ,35 /* ASCII j */
                        ,36 /* ASCII k */
                        ,37 /* ASCII l */
                        ,38 /* ASCII m */
                        ,39 /* ASCII n */
                        ,40 /* ASCII o */
                        ,41 /* ASCII p */
                        ,42 /* ASCII q */
                        ,43 /* ASCII r */
                        ,44 /* ASCII s */
                        ,45 /* ASCII t */
                        ,46 /* ASCII u */
                        ,47 /* ASCII v */
                        ,48 /* ASCII w */
                        ,49 /* ASCII x */
                        ,50 /* ASCII y */
                        ,51 /* ASCII z */
                        ,75 /* ASCII { */
                        ,75 /* ASCII | */
                        ,75 /* ASCII } */
                        ,75 /* ASCII ~ */
                        ,77 /* ASCII(DEC) 127 */
                        ,77 /* ASCII(DEC) 128 */
                        ,77 /* ASCII(DEC) 129 */
                        ,77 /* ASCII(DEC) 130 */
                        ,77 /* ASCII(DEC) 131 */
                        ,77 /* ASCII(DEC) 132 */
                        ,77 /* ASCII(DEC) 133 */
                        ,77 /* ASCII(DEC) 134 */
                        ,77 /* ASCII(DEC) 135 */
                        ,77 /* ASCII(DEC) 136 */
                        ,77 /* ASCII(DEC) 137 */
                        ,77 /* ASCII(DEC) 138 */
                        ,77 /* ASCII(DEC) 139 */
                        ,77 /* ASCII(DEC) 140 */
                        ,77 /* ASCII(DEC) 141 */
                        ,77 /* ASCII(DEC) 142 */
                        ,77 /* ASCII(DEC) 143 */
                        ,77 /* ASCII(DEC) 144 */
                        ,77 /* ASCII(DEC) 145 */
                        ,77 /* ASCII(DEC) 146 */
                        ,77 /* ASCII(DEC) 147 */
                        ,77 /* ASCII(DEC) 148 */
                        ,77 /* ASCII(DEC) 149 */
                        ,77 /* ASCII(DEC) 150 */
                        ,77 /* ASCII(DEC) 151 */
                        ,77 /* ASCII(DEC) 152 */
                        ,77 /* ASCII(DEC) 153 */
                        ,77 /* ASCII(DEC) 154 */
                        ,77 /* ASCII(DEC) 155 */
                        ,77 /* ASCII(DEC) 156 */
                        ,77 /* ASCII(DEC) 157 */
                        ,77 /* ASCII(DEC) 158 */
                        ,77 /* ASCII(DEC) 159 */
                        ,77 /* ASCII(DEC) 160 */
                        ,77 /* ASCII(DEC) 161 */
                        ,77 /* ASCII(DEC) 162 */
                        ,77 /* ASCII(DEC) 163 */
                        ,77 /* ASCII(DEC) 164 */
                        ,77 /* ASCII(DEC) 165 */
                        ,77 /* ASCII(DEC) 166 */
                        ,77 /* ASCII(DEC) 167 */
                        ,77 /* ASCII(DEC) 168 */
                        ,77 /* ASCII(DEC) 169 */
                        ,77 /* ASCII(DEC) 170 */
                        ,77 /* ASCII(DEC) 171 */
                        ,77 /* ASCII(DEC) 172 */
                        ,77 /* ASCII(DEC) 173 */
                        ,77 /* ASCII(DEC) 174 */
                        ,77 /* ASCII(DEC) 175 */
                        ,77 /* ASCII(DEC) 176 */
                        ,77 /* ASCII(DEC) 177 */
                        ,77 /* ASCII(DEC) 178 */
                        ,77 /* ASCII(DEC) 179 */
                        ,77 /* ASCII(DEC) 180 */
                        ,77 /* ASCII(DEC) 181 */
                        ,77 /* ASCII(DEC) 182 */
                        ,77 /* ASCII(DEC) 183 */
                        ,77 /* ASCII(DEC) 184 */
                        ,77 /* ASCII(DEC) 185 */
                        ,77 /* ASCII(DEC) 186 */
                        ,77 /* ASCII(DEC) 187 */
                        ,77 /* ASCII(DEC) 188 */
                        ,77 /* ASCII(DEC) 189 */
                        ,77 /* ASCII(DEC) 190 */
                        ,77 /* ASCII(DEC) 191 */
                        ,77 /* ASCII(DEC) 192 */
                        ,77 /* ASCII(DEC) 193 */
                        ,77 /* ASCII(DEC) 194 */
                        ,77 /* ASCII(DEC) 195 */
                        ,77 /* ASCII(DEC) 196 */
                        ,77 /* ASCII(DEC) 197 */
                        ,77 /* ASCII(DEC) 198 */
                        ,77 /* ASCII(DEC) 199 */
                        ,77 /* ASCII(DEC) 200 */
                        ,77 /* ASCII(DEC) 201 */
                        ,77 /* ASCII(DEC) 202 */
                        ,77 /* ASCII(DEC) 203 */
                        ,77 /* ASCII(DEC) 204 */
                        ,77 /* ASCII(DEC) 205 */
                        ,77 /* ASCII(DEC) 206 */
                        ,77 /* ASCII(DEC) 207 */
                        ,77 /* ASCII(DEC) 208 */
                        ,77 /* ASCII(DEC) 209 */
                        ,77 /* ASCII(DEC) 210 */
                        ,77 /* ASCII(DEC) 211 */
                        ,77 /* ASCII(DEC) 212 */
                        ,77 /* ASCII(DEC) 213 */
                        ,77 /* ASCII(DEC) 214 */
                        ,77 /* ASCII(DEC) 215 */
                        ,77 /* ASCII(DEC) 216 */
                        ,77 /* ASCII(DEC) 217 */
                        ,77 /* ASCII(DEC) 218 */
                        ,77 /* ASCII(DEC) 219 */
                        ,77 /* ASCII(DEC) 220 */
                        ,77 /* ASCII(DEC) 221 */
                        ,77 /* ASCII(DEC) 222 */
                        ,77 /* ASCII(DEC) 223 */
                        ,77 /* ASCII(DEC) 224 */
                        ,77 /* ASCII(DEC) 225 */
                        ,77 /* ASCII(DEC) 226 */
                        ,77 /* ASCII(DEC) 227 */
                        ,77 /* ASCII(DEC) 228 */
                        ,77 /* ASCII(DEC) 229 */
                        ,77 /* ASCII(DEC) 230 */
                        ,77 /* ASCII(DEC) 231 */
                        ,77 /* ASCII(DEC) 232 */
                        ,77 /* ASCII(DEC) 233 */
                        ,77 /* ASCII(DEC) 234 */
                        ,77 /* ASCII(DEC) 235 */
                        ,77 /* ASCII(DEC) 236 */
                        ,77 /* ASCII(DEC) 237 */
                        ,77 /* ASCII(DEC) 238 */
                        ,77 /* ASCII(DEC) 239 */
                        ,77 /* ASCII(DEC) 240 */
                        ,77 /* ASCII(DEC) 241 */
                        ,77 /* ASCII(DEC) 242 */
                        ,77 /* ASCII(DEC) 243 */
                        ,77 /* ASCII(DEC) 244 */
                        ,77 /* ASCII(DEC) 245 */
                        ,77 /* ASCII(DEC) 246 */
                        ,77 /* ASCII(DEC) 247 */
                        ,77 /* ASCII(DEC) 248 */
                        ,77 /* ASCII(DEC) 249 */
                        ,77 /* ASCII(DEC) 250 */
                        ,77 /* ASCII(DEC) 251 */
                        ,77 /* ASCII(DEC) 252 */
                        ,77 /* ASCII(DEC) 253 */
                        ,77 /* ASCII(DEC) 254 */
                        ,77 /* ASCII(DEC) 255 */
                    };