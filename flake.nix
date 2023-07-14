{
    description = "G++ compiler with C++14 standard";
    inputs = {
        nixpkgs.url = github:NixOS/nixpkgs;
        flake-utils.url = github:numtide/flake-utils;
    };
    outputs = { self, nixpkgs, flake-utils }: 
        flake-utils.lib.eachDefaultSystem (system:
            let
                pkgs = import nixpkgs { inherit system; };
            in
            {
                packages.default = pkgs.stdenv.mkDerivation { 
                    name = "result_option";
                    src = self;

                    buildInputs = [ 
                        pkgs.gpp
                        pkgs.gdb
                    ];
                    shellHook = ''
                        echo C++!
                    '';
                    buildPhase = "g++ -o test main.cpp";
                    installPhase = ''
                    mkdir -p $out/bin
                    install -t $out/bin test
                    '';
                };
            });
}