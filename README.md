<div align="center">
  <img src="images/protopirate_10px.png" alt="Icon" width="80" />
  <h1>ProtoPirate</h1>
  <p><strong>Toolkit d'analyse de rolling codes Sub-GHz pour Flipper Zero — v1.0</strong></p>
  <p>
    <a href="https://github.com/Carlitack/protocabrax/actions">
      <img src="https://github.com/Carlitack/protocabrax/actions/workflows/build.yml/badge.svg" alt="Build">
    </a>
    <a href="https://joelewis012.github.io/flipper-fap-actions/">
      <img src="https://img.shields.io/badge/FlipperFAP-Ready-FF4400" alt="FlipperFAP">
    </a>
    <img src="https://img.shields.io/badge/Flipper_Zero-FAP-blue" alt="Flipper Zero">
  </p>
  <p>
    <strong>Fork amélioré par <a href="https://github.com/Carlitack">Carlitack</a></strong>
  </p>
</div>

---

**ProtoPirate** est un toolkit d'analyse et de décodage de rolling codes
automobile pour Flipper Zero, développé par **The Pirates' Plunder**.

> ✅ **Émission activée par défaut** – Prêt à émettre. Désactive-la dans
> **Settings** si besoin.

---

## 📋 Toutes les features

### 📡 Capture & Analyse
| Feature | Description |
|---|---|
| **Récepteur temps réel** | Capture et décode les signaux Sub-GHz en direct |
| **Radar animé** | Affichage radar des signaux reçus |
| **Frequency Hopping** | Saute automatiquement entre les fréquences |
| **RSSI threshold** | Déclenchement sur seuil de signal |

### 📂 Post-traitement
| Feature | Description |
|---|---|
| **Sub Decode** | Analyse les fichiers `.sub` existants sur la SD |
| **Saved Captures** | Historique des signaux capturés |
| **Export CSV** | Exporte les données décodées au format CSV |
| **Delete** | Suppression des captures depuis l'interface |

### 🎛️ Émulation & Transmission
| Feature | Description |
|---|---|
| **Emulate** | Ré-émet un signal capturé (bouton par bouton) |
| **Compteur persistant** | Le rolling counter est sauvegardé sur la SD à chaque appui |
| **TX activé par défaut** | Plus besoin d'activer le mode dans Settings |
| **HITAG2 key prompt** | Saisie de clé HITAG2 pour Fiat V1 |
| **PSA Bruteforce** | Plugin de bruteforce XTEA pour Peugeot/Citroën |
| **Replay / Rolling** | Adapte le comportement selon le protocole |

### ⏱️ Outils Développeur
| Feature | Description |
|---|---|
| **Timing Tuner** 🔓 | Compare le timing réel d'une télécommande contre la définition |
| **Protocol Help** 📖 | Documentation des protocoles par marque intégrée à l'app |
| **Frequency Analyzer** | Mesure et affiche la fréquence active |

### 🎨 Interface
| Feature | Description |
|---|---|
| **Scrolling credits** | Crédits animés dans la scène About |
| **Emulate toggle combo** | Konami code (↑↑↓↓←→←→) pour toggle l'émulation |
| **Badge FlipperFAP** | Crédits "Compiled with FlipperFAP" |
| **Configuration** | Fréquence, hopping, TX power, auto-save |

---

## 🔐 Moteurs crypto

| Crypto | Utilisation |
|---|---|
| **KeeLoq** | StarLine, Kia V3/V4 — 528 rounds, NLF 0x3A5C742E |
| **KeeLoq Secure (type 3)** 🔓 | Nouveau — ajouté |
| **KeeLoq FAAC (type 5)** 🔓 | Nouveau — ajouté |
| **AUT64** | VAG (VW/Audi/Seat/Skoda) — 12 rounds, 8-byte blocks 🔓 |
| **XTEA** | PSA (Peugeot/Citroën) chiffrement/déchiffrement |
| **HITAG2** | Fiat V1 — prompt clé utilisateur |
| **AES-128** | Kia V6 |
| **CRC GF(2) matrix** | Ford V0 |
| **Rolling code** | Ford, Kia, Honda, Mazda, Subaru, Chrysler… |

---

## 🚗 Protocoles supportés

### AM (16 protocoles)
| Protocole | Decode | Encode | Crypto | Fréquence |
|---|---|---|---|---|
| Chrysler V0 | ✅ | ✅ | Rolling Code | 315 / 433 |
| Fiat V0 | ✅ | ✅ | Rolling Code | 315 / 433 |
| Fiat V1 | ✅ | ✅ | HITAG2 | 315 / 433 |
| Fiat V2 | ✅ | ❌ | Rolling Code | 315 / 433 |
| Ford V0 | ✅ | ✅ | Rolling + CRC | 315 / 433 |
| Ford V3 | ✅ | ❌ | Rolling Code | 434 |
| Honda V1 | ✅ | ✅ | Rolling + CRC4 | 315 / 433 |
| Kia V1 | ✅ | ✅ | Rolling + CRC4 | 315 / 433 |
| Kia V2 | ✅ | ✅ | Rolling + CRC4 | 315 / 433 |
| Mazda V0 | ✅ | ✅ | Rolling Code | 315 / 433 |
| Porsche Touareg | ✅ | ❌ | Rolling Code | 315 |
| PSA | ✅ | ✅ | XTEA/XOR + CRC8 | 315 / 433 |
| Renault V0 | ✅ | ✅ | Rolling / Replay | 315 / 433 |
| StarLine | ✅ | ✅ | KeeLoq | 315 / 433 |
| Subaru | ✅ | ✅ | Rolling Code | 315 / 433 |
| VAG | ✅ | ✅ | AUT64/XTEA | 434 |

### FM (14 protocoles)
| Protocole | Decode | Encode | Crypto | Fréquence |
|---|---|---|---|---|
| Ford V1 | ✅ | ✅ | Rolling + CRC16 | 315 / 433 |
| Ford V2 | ✅ | ✅ | Replay | 434 |
| Ford V3 | ✅ | ❌ | Rolling Code | 434 |
| Honda Static | ✅ | ✅ | Code statique | 315 / 433 |
| Honda V0 | ✅ | ✅ | Rolling + CRC8 | 315 / 433 |
| Honda V2 | ✅ | ✅ | Rolling Code | 315 / 433 |
| Kia V0 | ✅ | ✅ | Rolling + CRC8 | 315 / 433 |
| Kia V3/V4 | ✅ | ✅ | KeeLoq + CRC4 | 315 / 433 |
| Kia V5 | ✅ | ✅ | Rolling Code | 315 / 433 |
| Kia V6 | ✅ | ✅ | AES-128 + CRC8 | 315 / 433 |
| Kia V7 | ✅ | ✅ | Rolling + CRC8 | 315 / 433 |
| Mazda V0 | ✅ | ✅ | Rolling Code | 315 / 433 |
| Mitsubishi V0 | ✅ | ❌ | Rolling Code | 315 / 433 |
| Scher-Khan | ✅ | ❌ | Magic Code | 315 / 433 |

---

## ✨ Améliorations du fork

| # | Amélioration | Détail |
|---|---|---|
| 1 | 🔓 **Timing Tuner débloqué** | Scène activée (était commentée) |
| 2 | 🔓 **AUT64 validations + pack** | Key validation et serialization activées |
| 3 | 🔓 **KeeLoq Secure (type 3)** | Implémentation ajoutée |
| 4 | 🔓 **KeeLoq FAAC (type 5)** | Implémentation ajoutée |
| 5 | ✅ **TX activé par défaut** | `emulate_feature_enabled = true` |
| 6 | ✅ **Compteur persistant** | Sauvegardé sur SD à chaque appui en emulate |
| 7 | ✅ **Logging réparé** | `FURI_LOG_E/W` actifs (étaient tués) |
| 8 | ✅ **39 blocks dead code supprimés** | `#ifndef REMOVE_LOGS` nettoyés |
| 9 | ✅ **StarLine TODOs fixés** | Null guard + reset propre |
| 10 | ✅ **CI GitHub Actions** | 4 builds (OFW/Unleashed/Momentum + dev) |
| 11 | ✅ **Protocol Help scene** | Doc embarquée par marque |
| 12 | ✅ **Export CSV** | Export des données décodées |
| 13 | ✅ **FlipperFAP Badge** | Crédits dans About |
| 14 | ✅ **Tests KeeLoq** | 14/14 standalone |
| 15 | ✅ **Tests AUT64** | 16/20 standalone |

---

## 🎯 Comment utiliser Protocabrax

### 1. Capture un signal

```
Menu Principal → Receive
```

1. Sélectionne une **fréquence** (315, 433, 434 MHz…)
2. Pointe ton Flipper vers la télécommande
3. Appuie sur le bouton de la télécommande
4. Le signal apparaît à l'écran → **OK** pour le verrouiller
5. **Sauvegarde** le signal (nom automatique ou personnalisé)

### 2. Analyse un signal sauvegardé

```
Menu Principal → Saved Captures → sélectionne un signal
```

- Voir les infos décodées (SN, Btn, Counter, Crypto…)
- **CSV** → Exporte les données pour analyse PC
- **Emulate** → Ré-émet le signal
- **Delete** → Supprime la capture

### 3. Sub Decode (fichiers .sub existants)

```
Menu Principal → Sub Decode
```

Charge un fichier `.sub` depuis la carte SD et le décode.

### 4. Émuler un signal

Depuis **Saved Captures → Emulate** ou depuis l'info d'un signal :

- Les boutons du Flipper correspondent aux boutons de la télécommande
- Le **compteur** s'incrémente à chaque appui et se sauvegarde
- Maintenir enfoncé = transmission continue
- Relâcher = stop
- **Back** pour quitter

### 5. Timing Tuner (pour développeurs)

```
Menu Principal → Timing Tuner
```

Compare le timing d'une télécommande réelle contre les constantes
du protocole. Affiche short/long pulse, jitter, tolérance.

### 6. Configuration

```
Menu Principal → Configuration
```

- **Frequency** : Fréquence de capture
- **Hopping** : Saute automatiquement entre fréquences
- **TX Power** : Puissance d'émission (0-8)
- **Auto Save** : Sauvegarde automatique
- **Emulate Feature** : Active/désactive l'émission

### 7. Protocols Help (documentation embarquée)

```
Menu Principal → Protocols Help
```

Documentation complète par marque : Ford, Kia, VAG, PSA, Fiat, Honda…
Scrolling dans l'app.

---

## 🔧 Compilation

### En ligne — FlipperFAP (aucune installation)
```
https://joelewis012.github.io/flipper-fap-actions/
→ colle https://github.com/Carlitack/protocabrax
→ choisis ton firmware
→ ⚙ COMPILE .FAP
```

### GitHub Actions (automatique)
Chaque push sur `main` → 4 builds disponibles dans l'onglet Actions :
- `protocabrax_ofw_release` / `protocabrax_ofw_dev`
- `protocabrax_unleashed`
- `protocabrax_momentum`

### Local (ufbt)
```bash
pip install ufbt
cd protocabrax && ufbt
```

---

## 📦 Builds disponibles

| Firmware | Artifact |
|---|---|
| **Official Release** | `protocabrax_ofw_release` |
| **Official Dev** | `protocabrax_ofw_dev` |
| **Unleashed** | `protocabrax_unleashed` |
| **Momentum** | `protocabrax_momentum` |
| **RogueMaster** | Utilise le build Unleashed |

---

## 🧪 Tests
```bash
cd tests
gcc -o test_keeloq test_keeloq.c -lm && ./test_keeloq   # 14/14 ✅
gcc -o test_aut64 test_aut64.c -lm && ./test_aut64       # 16/20 ✅
```

---

## 🙏 Credits

**App Development:** RocketGod, MMX, Leeroy, gullradriel, Skorp, Vadim
**Protocol Magic:** L0rdDiakon, YougZ, RocketGod, MMX, DoobTheGoober, Skorp, Slackware, Trikk, Wootini, Li0ard, Leeroy, Ash
**RE Support:** DoobTheGoober, MMX, NeedNotApply, RocketGod, Slackware, Trikk, Li0ard
**Online Compiler:** [FlipperFAP](https://joelewis012.github.io/flipper-fap-actions/)
**Community:** [discord.gg/thepirates](https://discord.gg/thepirates)

---

## 📝 Licence

**GPLv3** — original par **The Pirates' Plunder**
