{ pkgs ? import <nixpkgs> {} }:
  pkgs.mkShell {
    packages = with pkgs; [
      nasm
      gnumake
      criterion
    ];
}
