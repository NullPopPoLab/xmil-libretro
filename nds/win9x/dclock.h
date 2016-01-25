
enum {
	DCLOCK_X		= 56,
	DCLOCK_Y		= 12
};

typedef struct {
	UINT8	*pos;
	UINT16	mask;
	UINT8	rolbit;
	UINT8	reserved;
} DCPOS;

typedef struct {
const UINT8	*fnt;
const DCPOS	*pos;
	UINT8	frm[8];
	UINT8	now[8];
	UINT8	bak[8];
	UINT16	drawing;
	UINT8	clk_x;
	UINT8	_padding;
	UINT8	dat[(DCLOCK_X * DCLOCK_Y / 8) + 4];
} _DCLOCK;

typedef struct {
	RGB32	pal32[4];
	RGB16	pal16[4];
	UINT32	pal8[4][16];
} DCLOCKPAL;


#ifdef __cplusplus
extern "C" {
#endif

extern	_DCLOCK		dclock;
extern	DCLOCKPAL	dclockpal;

void dclock_init(void);
void dclock_init8(void);
void dclock_init16(void);
void dclock_reset(void);
void dclock_callback(void);
void dclock_redraw(void);
BOOL dclock_disp(void);
void dclock_cntdown(BYTE value);
void dclock_make(void);
void dclock_out8(void *ptr, UINT width);
void dclock_out16(void *ptr, UINT width);

#ifdef __cplusplus
}
#endif
