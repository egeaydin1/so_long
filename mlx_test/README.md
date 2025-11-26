# MiniLibX Test - Red Square

Basit bir MiniLibX alıştırma programı. Kırmızı bir kareyi klavye ile hareket ettirebilirsiniz.

## Özellikler

- Kırmızı kare (64x64 piksel)
- WASD veya Ok tuşlarıyla hareket
- Ekranda pozisyon gösterimi
- Sınır kontrolü (pencere dışına çıkmaz)

## Kurulum

```bash
# Derleme
make

# Çalıştırma
./mlx_test

# Veya direkt
make run
```

## Kontroller

- **W** veya **↑** → Yukarı
- **S** veya **↓** → Aşağı
- **A** veya **←** → Sol
- **D** veya **→** → Sağ
- **ESC** → Çıkış

## Dosya Yapısı

```
mlx_test/
├── test.c                  # Ana program
├── Makefile               # Derleme kuralları
├── mlx/                   # MiniLibX kütüphanesi
└── textures/
    └── red_square.xpm     # Kırmızı kare texture
```

## Öğrenilenler

### MiniLibX Temelleri
- `mlx_init()` - MiniLibX başlatma
- `mlx_new_window()` - Pencere oluşturma
- `mlx_loop()` - Ana oyun döngüsü

### Image İşlemleri
- `mlx_xpm_file_to_image()` - XPM dosyasından texture yükleme
- `mlx_put_image_to_window()` - Texture'ı ekrana çizme
- `mlx_destroy_image()` - Image'ı bellekten temizleme

### Event Yönetimi
- `mlx_hook()` - Event dinleyici bağlama
- Key press eventi (tuş basma)
- Window close eventi (pencere kapatma)

### Render Sistemi
- `mlx_clear_window()` - Ekranı temizleme
- `mlx_string_put()` - Ekrana yazı yazdırma
- Her frame'de yeniden çizim

## Geliştirme Önerileri

### 1. Hızı Değiştir
```c
// test.c içinde
int move_speed = 20; // Daha hızlı
int move_speed = 5;  // Daha yavaş
```

### 2. Farklı Renk
```bash
# textures/red_square.xpm dosyasında
"# c #FF0000",  # Kırmızı
# değiştir:
"# c #0000FF",  # Mavi
"# c #00FF00",  # Yeşil
```

### 3. Animasyon
```c
// Sürekli hareket eden kare
int loop_hook(t_data *data)
{
    data->x += 2;
    if (data->x > WIN_WIDTH)
        data->x = -TILE_SIZE;
    render(data);
    return (0);
}

// main() içinde ekle:
mlx_loop_hook(data.mlx, loop_hook, &data);
```

## So Long Projesi için Hazırlık

Bu basit program, So Long projesi için temel oluşturur:

| MLX Test | → | So Long |
|----------|---|---------|
| 1 kare | → | Map sistemi |
| Siyah arka plan | → | Floor/Wall texture'ları |
| Free movement | → | Grid tabanlı hareket |
| Sınır kontrolü | → | Duvar kontrolü |
| Basit render | → | Katmanlı render sistemi |

## Sorun Giderme

### Texture yüklenmiyor
```bash
# Dosya var mı kontrol et
ls textures/red_square.xpm

# İzinleri kontrol et
chmod 644 textures/red_square.xpm
```

### MLX hataları
```bash
# MLX'i yeniden derle
cd mlx
make clean
make
cd ..
make re
```

### Key kodları çalışmıyor
Program çalışırken tuşa bastığınızda terminal'de key code göreceksiniz.
Bu kodları `test.c` dosyasındaki define'lara ekleyebilirsiniz.

## Lisans

Bu bir eğitim projesidir. 42 Network öğrencileri için hazırlanmıştır.
