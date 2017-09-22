

void CRenderer::InterrogateTexture(LPDIRECT3DTEXTURE9 pTexture){
  D3DLOCKED_RECT r;
  HRESULT hr = pTexture->LockRect(0, &r, NULL, 0);
  if(hr == S_OK){
    int grey;
    for(int k=0; k<31; k++){
      grey = 0;
      for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
          grey += GetGray(r, k, i, j);
      grey = grey/64;
      printf("%d\t%d\n", k, grey);
    }
    pTexture->UnlockRect(0);
  }
}

int GetGray(D3DLOCKED_RECT r, int chr, int row, int col){
  BYTE* offset =
    (BYTE*)(r.pBits) + row*r.Pitch + chr*4*8 + col*4;
  return (int)(*offset) + *(offset + 1) + *(offset + 2);
}

texture Texture0;
texture Texture1;

sampler2D Sampler0 = sampler_state{
  Texture = <Texture0>;
};

sampler2D Sampler1 = sampler_state{
  Texture = <Texture1>;
};


float4 PS (in float2 Tex: TEXCOORD0): COLOR0{
  int CHARSIZE = 8;
  int GRAYLEVELS = 8;
  int IMGTEXTURESIZE = 2048;
  int CHARTEXTURESIZE = 512;
  int BLOCKSCALE = IMGTEXTURESIZE/CHARSIZE;

  float4 pix = tex2D(Sampler0, floor(BLOCKSCALE*Tex)/BLOCKSCALE);
  int gray = floor((pix.r + pix.g + pix.b)*GRAYLEVELS/3.0f);

  int2 inttex = floor(Tex * (IMGTEXTURESIZE - 1));
  int2 block = (inttex/CHARSIZE)*CHARSIZE;

  float2 offset = inttex - block + 1;
  offset.x += gray*CHARSIZE;
  offset /= CHARTEXTURESIZE - 1;
  return tex2D(Sampler1, offset);
}