/********PORT SET********/
#ifndef PORTA_SET
#define PORTA_SET(x) PORTA=PORTA|(1<<x)
#endif
#ifndef PORTB_SET
#define PORTB_SET(x) PORTB=PORTB|(1<<x)
#endif
#ifndef PORTC_SET
#define PORTC_SET(x) PORTC=PORTC|(1<<x)
#endif
#ifndef PORTD_SET
#define PORTD_SET(x) PORTD=PORTD|(1<<x)
#endif

/********PORT CLEAR********/
#ifndef PORTA_CLR
#define PORTA_CLR(x) PORTA=PORTA|(1<<x)
#endif
#ifndef PORTB_CLR
#define PORTB_CLR(x) PORTB=PORTB|(1<<x)
#endif
#ifndef PORTC_CLR
#define PORTC_CLR(x) PORTC=PORTC|(1<<x)
#endif
#ifndef PORTD_CLR
#define PORTD_CLR(x) PORTD=PORTD|(1<<x)
#endif

/********DDR OUT********/
#ifndef DDRA_OUT
#define DDRA_OUT(x) DDRA=DDRA|(1<<x)
#endif
#ifndef DDRB_OUT
#define DDRB_OUT(x) DDRB=DDRB|(1<<x)
#endif
#ifndef DDRC_OUT
#define DDRC_OUT(x) DDRC=DDRC|(1<<x)
#endif
#ifndef DDRD_OUT
#define DDRD_OUT(x) DDRD=DDRD|(1<<x)
#endif

/********PORT IN********/
#ifndef DDRA_IN
#define DDRA_IN(x) DDRA=DDRA|(1<<x)
#endif
#ifndef DDRB_IN
#define DDRB_IN(x) DDRB=DDRB|(1<<x)
#endif
#ifndef DDRC_IN
#define DDRC_IN(x) DDRC=DDRC|(1<<x)
#endif
#ifndef DDRD_IN
#define DDRD_IN(x) DDRD=DDRD|(1<<x)
#endif

/********PIN READ********/
#ifndef PINA_READ
#define PINA_READ(x) ((PINA>>x)&0x01)
#endif
#ifndef PINA_READ
#define PINA_READ(x) ((PINA>>x)&0x01)
#endif
#ifndef PINA_READ
#define PINA_READ(x) ((PINA>>x)&0x01)
#endif
#ifndef PINA_READ
#define PINA_READ(x) ((PINA>>x)&0x01)
#endif