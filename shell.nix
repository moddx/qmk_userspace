{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  # nativeBuildInputs is usually what you want -- tools you need to run
  nativeBuildInputs = with pkgs.buildPackages; [
    qmk
    python313
    python313Packages.pip
  ];
  shellHook = ''
    python -m venv .venv
    source .venv/bin/activate
    pip install -r ../qmk_firmware/requirements.txt
  '';
}

