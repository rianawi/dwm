pkgname=dwm
pkgver=6.0
pkgrel=1
pkgdesc="A dynamic window manager for X"
url="http://dwm.suckless.org"
arch=('i686' 'x86_64')
license=('MIT')
options=(zipman)
depends=('libx11' 'libxinerama')
install=dwm.install
source=(http://dl.suckless.org/dwm/dwm-$pkgver.tar.gz
	dwm.desktop
	config.h
  bstack.c
  gaplessgrid.c
  push.c)
_patches=(01-statuscolours.diff
          02-monoclecount.diff
          03-noborder.diff
          04-centredfloating.diff
          05-scratchpad.diff
          06-attachaside.diff
          07-nopaddedbar.diff)
source=(${source[@]} ${_patches[@]})

build() {
  cd $srcdir/$pkgname-$pkgver


  for p in "${_patches[@]}"; do
    echo "=> $p"
    patch < ../$p || return 1
  done

  cp $srcdir/config.h config.h
  cp $srcdir/bstack.c bstack.c
  cp $srcdir/gaplessgrid.c gaplessgrid.c
  cp $srcdir/push.c push.c

  sed -i 's/CPPFLAGS =/CPPFLAGS +=/g' config.mk
  sed -i 's/^CFLAGS = -g/#CFLAGS += -g/g' config.mk
  sed -i 's/^#CFLAGS = -std/CFLAGS += -std/g' config.mk
  sed -i 's/^LDFLAGS = -g/#LDFLAGS += -g/g' config.mk
  sed -i 's/^#LDFLAGS = -s/LDFLAGS += -s/g' config.mk
  make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11
}

package() {
  cd $srcdir/$pkgname-$pkgver
  make PREFIX=/usr DESTDIR=$pkgdir install
  install -m644 -D LICENSE $pkgdir/usr/share/licenses/$pkgname/LICENSE
  install -m644 -D README $pkgdir/usr/share/doc/$pkgname/README
  install -m644 -D $srcdir/dwm.desktop $pkgdir/usr/share/xsessions/dwm.desktop
}
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '939f403a71b6e85261d09fc3412269ee'
         '67e982905726fad75ccad7560f53d41f'
         '362e07f0f042875b84d7739d9d8855c4'
         '4ba509b3b93f7b1418dc703c70de536f'
         '689534c579b1782440ddcaf71537d8fd'
         '57b1a8f21b61c55f906d7cc075111613'
         'e3faeea09a554bbbce29c4d480b0ca41'
         '1f0244803c0188f1b6f4e5794e7f5ca2'
         'ed11483bfccbf65ff9714c0ca4e7bb23'
         'bc6240f3adadf604a450f6375badec61'
         'a92ee04c33b1082da61b55d3617249eb'
         '29213fff0d93fc3a7183948f6c792ac5')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '939f403a71b6e85261d09fc3412269ee'
         '05bceca9c7dee80669a6a50c294843f8'
         '362e07f0f042875b84d7739d9d8855c4'
         '4ba509b3b93f7b1418dc703c70de536f'
         '689534c579b1782440ddcaf71537d8fd'
         '57b1a8f21b61c55f906d7cc075111613'
         'e3faeea09a554bbbce29c4d480b0ca41'
         '1f0244803c0188f1b6f4e5794e7f5ca2'
         'ed11483bfccbf65ff9714c0ca4e7bb23'
         'bc6240f3adadf604a450f6375badec61'
         'a92ee04c33b1082da61b55d3617249eb'
         '29213fff0d93fc3a7183948f6c792ac5')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '939f403a71b6e85261d09fc3412269ee'
         'b65b5bbb1a289fad04e1bc726178ebe0'
         '362e07f0f042875b84d7739d9d8855c4'
         '4ba509b3b93f7b1418dc703c70de536f'
         '689534c579b1782440ddcaf71537d8fd'
         '57b1a8f21b61c55f906d7cc075111613'
         'e3faeea09a554bbbce29c4d480b0ca41'
         '1f0244803c0188f1b6f4e5794e7f5ca2'
         'ed11483bfccbf65ff9714c0ca4e7bb23'
         'bc6240f3adadf604a450f6375badec61'
         'a92ee04c33b1082da61b55d3617249eb'
         '29213fff0d93fc3a7183948f6c792ac5')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '939f403a71b6e85261d09fc3412269ee'
         'db9b3d10f10a4ae10ff6f602cf4d20ae'
         '362e07f0f042875b84d7739d9d8855c4'
         '4ba509b3b93f7b1418dc703c70de536f'
         '689534c579b1782440ddcaf71537d8fd'
         '57b1a8f21b61c55f906d7cc075111613'
         'e3faeea09a554bbbce29c4d480b0ca41'
         '1f0244803c0188f1b6f4e5794e7f5ca2'
         'ed11483bfccbf65ff9714c0ca4e7bb23'
         'bc6240f3adadf604a450f6375badec61'
         'a92ee04c33b1082da61b55d3617249eb'
         '29213fff0d93fc3a7183948f6c792ac5')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '939f403a71b6e85261d09fc3412269ee'
         '688250f5ca36ce596cfa507549fd9aa0'
         '362e07f0f042875b84d7739d9d8855c4'
         '4ba509b3b93f7b1418dc703c70de536f'
         '689534c579b1782440ddcaf71537d8fd'
         '57b1a8f21b61c55f906d7cc075111613'
         'e3faeea09a554bbbce29c4d480b0ca41'
         '1f0244803c0188f1b6f4e5794e7f5ca2'
         'ed11483bfccbf65ff9714c0ca4e7bb23'
         'bc6240f3adadf604a450f6375badec61'
         'a92ee04c33b1082da61b55d3617249eb'
         '29213fff0d93fc3a7183948f6c792ac5')
