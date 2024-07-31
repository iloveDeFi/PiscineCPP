#!/bin/bash

# Fonction pour générer le code de la classe
generate_class_code() {
  local class_name=$1
  shift
  local attributes=("$@")

  # Début de la classe
  class_code="class $class_name:\n"
  class_code+="$(
    cat <<EOF
    def __init__(self, $(IFS=, ; echo "${attributes[*]}")):
EOF
  )"

  # Ajouter les attributs au constructeur
  for attr in "${attributes[@]}"; do
    class_code+="\n        self.$attr = $attr"
  done

  # Générer les fonctions __repr__ et __eq__
  class_code+="\n\n    def __repr__(self):"
  class_code+="\n        return f\"<$class_name("
  for attr in "${attributes[@]}"; do
    class_code+="\n            $attr={self.$attr!r},"
  done
  class_code+="\n        )>\""

  class_code+="\n\n    def __eq__(self, other):"
  class_code+="\n        if isinstance(other, $class_name):"
  class_code+="\n            return ("
  for attr in "${attributes[@]}"; do
    class_code+="\n                self.$attr == other.$attr and"
  done
  class_code+="\n            )"
  class_code+="\n        return False"

  echo -e "$class_code"
}

# Demander le nom de la classe
read -p "Nom de la classe: " class_name

# Demander les attributs
read -p "Attributs (séparés par des espaces): " -a attributes

# Générer le code de la classe
class_code=$(generate_class_code "$class_name" "${attributes[@]}")

# Créer le fichier Python
file_name="${class_name,,}.py"
echo -e "$class_code" > "$file_name"

echo "Classe $class_name générée dans le fichier $file_name"
