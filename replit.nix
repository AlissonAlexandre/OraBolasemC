{ pkgs }: {
	deps = [
		pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
    pkgs.gnuplot
    pkgs.busybox
	];
}